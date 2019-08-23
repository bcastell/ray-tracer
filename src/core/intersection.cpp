#include "intersection.h"

Intersection::Intersection() : t(0.0), point(Vector3()), normal(Vector3()), material(std::shared_ptr<Material>(nullptr)) {}

Intersection::Intersection(double t, const Vector3& point, const Vector3& normal, const std::shared_ptr<Material>& material)
    : t(t), point(point), normal(normal), material(material) {}

Intersection& Intersection::operator=(const Intersection& intersection) {
    t = intersection.t;
    point = intersection.point;
    normal = intersection.normal;
    material = intersection.material;

    return *this;
}