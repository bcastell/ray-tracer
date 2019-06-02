#ifndef SHAPE_H
#define SHAPE_H

#include "vector3.h"
#include "ray.h"

class Shape {
    public:
        virtual bool intersect(const Ray& ray, double t_min, double t_max, Vector3& normal) const = 0;
};

#endif