#include "intersection.h"

Intersection::Intersection() : t(0.0), point(Vector3(0.0, 0.0, 0.0)), normal(Vector3(0.0, 0.0, 0.0)) {}

Intersection::Intersection(double t, const Vector3& point, const Vector3& normal)
    : t(t), point(point), normal(normal) {}

Intersection& Intersection::operator=(const Intersection& intersection) {
    t = intersection.t;
    point = intersection.point;
    normal = intersection.normal;

    return *this;
}