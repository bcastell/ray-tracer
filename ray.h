#ifndef RAY_H
#define RAY_H

#include "vector3.h"

class Ray {
    public:
        Ray();
        Ray(const Vector3& origin, const Vector3& direction);
        Ray(const Ray& ray);

        Vector3 operator()(double t) const;

        Vector3 origin;
        Vector3 direction;
};

#endif