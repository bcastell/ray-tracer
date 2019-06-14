#ifndef SPHERE_H
#define SPHERE_H

#include "vector3.h"
#include "ray.h"
#include "shape.h"
#include "intersection.h"

class Sphere : public Shape {
    public:
        Sphere();
        Sphere(const Vector3& center, double radius);
        Sphere(const Sphere& sphere);

        bool intersect(const Ray& ray, double t_min, double t_max, Intersection& intersection) const;

        Vector3 center;
        double radius;
};

#endif