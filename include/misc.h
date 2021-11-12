#ifndef __MISC_H__
#define __MISC_H__

#include <cstdint>

struct Extent2D {
    union {
        uint32_t width;
        uint32_t x;
    };
    union {
        uint32_t height;
        uint32_t y;
    };
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

struct Color {
    uint32_t r;
    uint32_t g;
    uint32_t b;
    uint32_t a;
};

#endif
