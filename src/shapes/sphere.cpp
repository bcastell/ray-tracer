#include "sphere.h"

Sphere::Sphere(const Vector3& center, double radius, const std::shared_ptr<Material>& material) : center(center), radius(radius), material(material) {}

Sphere::~Sphere() {}

bool Sphere::intersect(const Ray& ray, double t_min, double t_max, Intersection& intersection) const {
    Vector3 oc = ray.origin - center;

    double a = ray.direction.dot(ray.direction);
    double b = 2.0 * ray.direction.dot(oc);
    double c = oc.dot(oc) - radius * radius;

    double discriminant = b * b - 4.0 * a * c;

    if (discriminant > 0) {
        double t = (-b - sqrt(discriminant)) / (2.0 * a);

        if (t <= t_min || t >= t_max) {
            t = (-b + sqrt(discriminant)) / (2.0 * a);

            if (t <= t_min || t >= t_max) {
                return false;
            }
        }

        intersection.t = t;
        intersection.point = ray(t);
        intersection.normal = (ray(t) - center).normalize();
        intersection.material = material;
        
        return true;
    }

    return false;
}