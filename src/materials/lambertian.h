#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "material.h"

class Lambertian : public Material {
    public:
        Lambertian(const Vector3& albedo);
        ~Lambertian();

        bool scatter(const Ray& incident_ray, const Intersection& intersection, Vector3& attenuation, Ray& scattered_ray) const;

        Vector3 albedo;
};

#endif