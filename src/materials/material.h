#ifndef MATERIAL_H
#define MATERIAL_H

class Intersection;

#include "ray.h"
#include "intersection.h"

class Material {
    public:
        virtual ~Material();

        virtual bool scatter(const Ray& incident_ray, const Intersection& intersection, Vector3& attenuation, Ray& scattered_ray) const = 0;
};

#endif