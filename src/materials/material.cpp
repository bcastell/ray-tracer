#include "material.h"

Material::~Material() {}

Vector3 Material::rejection_sample_unit_sphere() const {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::default_random_engine generator(seed);

    Vector3 sample;

    do {
        sample = Vector3(
            std::generate_canonical<double, std::numeric_limits<double>::digits>(generator),
            std::generate_canonical<double, std::numeric_limits<double>::digits>(generator),
            std::generate_canonical<double, std::numeric_limits<double>::digits>(generator)
        ) * 2.0 - Vector3(1.0, 1.0, 1.0);
    } while (sample.squared_length() >= 1.0);

    return sample;
}