#include "sampler.h"

Sampler::Sampler(uint64_t sample_count) : sample_count(sample_count), sample_index(0), samples(sample_count) {}

Sampler::~Sampler() {}

Vector3 Sampler::next_unit_square_sample() {
    if (sample_index == sample_count) {
        return Vector3(-1.0, -1.0, -1.0);
    }

    return samples[sample_index++];
}