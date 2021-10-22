#include <renderer.h>

#include <consts.h>

Renderer::Renderer(const Extent2D const *pExtent, const RenderingQueue const *pRenderingQueue,
             const ModellingQueue const *pModellingQueue)
    : pRenderingQueue = pRenderingQueue
    , pModellingQueue = pModellingQueue
    , window = window(sf::VideoMode(pExtent->width, pExtent->height, APP_NAME))
{}

Renderer::~Renderer() {}

int Renderer::renderFrame() {
    /* TODO: implement */
}
