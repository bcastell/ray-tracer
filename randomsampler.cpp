#include "randomsampler.h"

RandomSampler::RandomSampler(uint64_t sample_count) : Sampler(sample_count) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    generator = std::default_random_engine(seed);
}

void RandomSampler::sample_unit_square(const Vector3& top_left_corner) {
    sample_index = 0;

    for (uint64_t s = 0; s < sample_count; ++s) {
        double x_rand = std::generate_canonical<double, std::numeric_limits<double>::digits>(generator);
        double y_rand = std::generate_canonical<double, std::numeric_limits<double>::digits>(generator);

        samples[s] = Vector3(top_left_corner.x + x_rand, top_left_corner.y + y_rand, 0.0);
    }
}