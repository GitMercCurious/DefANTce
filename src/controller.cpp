#include <controller.h>

#include <fps_utils.h>

#include <chrono>
#include <thread>

Controller::Controller()
    : fpsHandler(controllerSettings.fps)
{
    pRenderingQueue = RenderingQueue::getInstance();
    pModelingQueue = ModelingQueue::getInstance();
    pUIEventsQueue = UIEventsQueue::getInstance();
    
    Renderer::settings = rendererSettings;
    Model::settings = modelSettings;

    Renderer::pRenderingQueue = pRenderingQueue;
    Renderer::pUIEventsQueue = pUIEventsQueue;

    Model::pRenderingQueue = pRenderingQueue;
    Model::pModelingQueue = pModelingQueue;

    pRenderer = Renderer::getInstance();
    pModel = Model::getInstance();
}

Controller *Controller::getInstance() {
    static Controller controller;
    return &controller;
}

Controller::~Controller() {}

void Controller::__convert_events() {
    pUIEventsQueue->poll([this](const QueueEvent &ev) {
        switch (ev.getType()) {
            case QueueEventType::MOUSE_CLICK:
            {
                auto *pEv = dynamic_cast<const MouseClickEvent *>(&ev);
                auto *pEvent = new AddParticleEvent;
                pEvent->x = pEv->x;
                pEvent->y = pEv->y;
                pModelingQueue->add(pEvent);
                break;
            }
            default:
                break;
        }
    });
}

void Controller::run() {
    while (true) {
        fpsHandler.startFrame();
        pModel->modelFrame();

        __convert_events();

        if (pRenderer->renderFrame()) {
            break;
        }
        fpsHandler.hang();
    }
}
