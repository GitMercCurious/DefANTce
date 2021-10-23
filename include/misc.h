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
            double x;
            double y;
        };
        double r[2];
    };
    union {
        struct {
            double vx;
            double vy;
        };
        double v[2];
    };
    bool valid;
};

#endif
