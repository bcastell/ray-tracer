#ifndef INTERSECTION_H
#define INTERSECTION_H

class Material;

#include <memory>

#include "ray.h"

class Intersection {
    public:
        Intersection();
        Intersection(double t, const Vector3& point, const Vector3& normal, const std::shared_ptr<Material>& material);

        Intersection& operator=(const Intersection& intersection);

        double t;
        Vector3 point;
        Vector3 normal;
        std::shared_ptr<Material> material;
};

#endif