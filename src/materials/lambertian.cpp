#include "lambertian.h"

Lambertian::Lambertian(const Vector3& albedo) : albedo(albedo) {}

Lambertian::~Lambertian() {}

bool Lambertian::scatter(const Ray& incident_ray, const Intersection& intersection, Vector3& attenuation, Ray& scattered_ray) const {
    Vector3 scattered_direction = intersection.normal + rejection_sample_unit_sphere();

    scattered_ray = Ray(intersection.point, scattered_direction);

    attenuation = albedo;

    return true;
}