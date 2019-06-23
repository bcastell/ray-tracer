#ifndef RANDOMSAMPLER_H
#define RANDOMSAMPLER_H

#include <chrono>
#include <random>

#include "sampler.h"

class RandomSampler : public Sampler {
    public:
        RandomSampler(uint64_t sample_count);

        void sample_unit_square(const Vector3& top_left_corner);

    private:
        std::default_random_engine generator;
};

#endif