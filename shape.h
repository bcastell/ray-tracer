#ifndef SHAPE_H
#define SHAPE_H

#include "ray.h"
#include "intersection.h"

class Shape {
    public:
        virtual bool intersect(const Ray& ray, double t_min, double t_max, Intersection& intersection) const = 0;
};

#endif