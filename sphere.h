#ifndef SPHERE_H
#define SPHERE_H

#include "vector3.h"
#include "ray.h"

class Sphere {
    public:
        Sphere();
        Sphere(const Vector3& center, double radius);
        Sphere(const Sphere& sphere);

        bool intersect(const Ray& ray) const;

        Vector3 center;
        double radius;
};

#endif