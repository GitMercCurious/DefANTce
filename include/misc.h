#ifndef __MISC_H__
#define __MISC_H__

#include <cstdint>

struct Extent2D {
    uint32_t width;
    uint32_t height;
};

struct Particle {
    union {
        struct {
            float x;
            float y;
        };
        float r[2];
    };
    union {
        struct {
            float vx;
            float vy;
        };
        float v[2];
    };
    bool valid;
};

#endif
