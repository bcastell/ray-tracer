#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include <chrono>
#include <random>
#include <limits>

#include "material.h"

class Lambertian : public Material {
    public:
        Lambertian(const Vector3& albedo);
        ~Lambertian();

        bool scatter(const Ray& incident_ray, const Intersection& intersection, Vector3& attenuation, Ray& scattered_ray) const;

        Vector3 albedo;

    private:
        Vector3 rejection_sample_unit_sphere() const;
};

#endif