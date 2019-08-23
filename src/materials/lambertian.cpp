#include "lambertian.h"

Lambertian::Lambertian(const Vector3& albedo) : albedo(albedo) {}

Lambertian::~Lambertian() {}

bool Lambertian::scatter(const Ray& incident_ray, const Intersection& intersection, Vector3& attenuation, Ray& scattered_ray) const {
    Vector3 scattered_direction = intersection.normal + rejection_sample_unit_sphere();

    scattered_ray = Ray(intersection.point, scattered_direction);

    attenuation = albedo;

    return true;
}

Vector3 Lambertian::rejection_sample_unit_sphere() const {
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