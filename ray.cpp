#include "ray.h"

Ray::Ray() : origin(Vector3(0.0, 0.0, 0.0)), direction(Vector3(0.0, 0.0, -1.0)) {}

Ray::Ray(const Vector3& origin, const Vector3& direction) : origin(origin), direction(direction) {}

Ray::Ray(const Ray& ray) : origin(ray.origin), direction(ray.direction) {}

Vector3 Ray::operator()(double t) const {
    return origin + t * direction;
}