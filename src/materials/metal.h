#ifndef METAL_H
#define METAL_H

#include "material.h"

class Metal : public Material {
    public:
        Metal(const Vector3& albedo, double fuzziness);
        ~Metal();

        bool scatter(const Ray& incident_ray, const Intersection& intersection, Vector3& attenuation, Ray& scattered_ray) const;

        Vector3 albedo;
        double fuzziness;

    private:
        Vector3 reflect(const Vector3& v, const Vector3& n) const;
};

#endif