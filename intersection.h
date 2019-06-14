#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "vector3.h"

class Intersection {
    public:
        Intersection();
        Intersection(double t, const Vector3& point, const Vector3& normal);

        Intersection& operator=(const Intersection& intersection);

        double t;
        Vector3 point;
        Vector3 normal;
};

#endif