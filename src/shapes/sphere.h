#ifndef SPHERE_H
#define SPHERE_H

#include <memory>

#include "vector3.h"
#include "ray.h"
#include "shape.h"
#include "intersection.h"
#include "material.h"

class Sphere : public Shape {
    public:
        Sphere(const Vector3& center, double radius, const std::shared_ptr<Material>& material);
        ~Sphere();

        bool intersect(const Ray& ray, double t_min, double t_max, Intersection& intersection) const;

        Vector3 center;
        double radius;
        std::shared_ptr<Material> material;
};

#endif