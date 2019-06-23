#ifndef SAMPLER_H
#define SAMPLER_H

#include <cstdint>
#include <vector>

#include "vector3.h"

class Sampler {
    public:
        Sampler(uint64_t sample_count);

        virtual void sample_unit_square(const Vector3& top_left_corner) = 0;

        Vector3 next_unit_square_sample();

    protected:
        uint64_t sample_count;
        uint64_t sample_index;

        std::vector<Vector3> samples;
};

#endif