#include "sphere.h"

Sphere::Sphere() : center(Vector3(0.0, 0.0, 0.0)), radius(1.0) {}

Sphere::Sphere(const Vector3& center, double radius) : center(center), radius(radius) {}

Sphere::Sphere(const Sphere& sphere) : center(sphere.center), radius(sphere.radius) {}

bool Sphere::intersect(const Ray& ray, double t_min, double t_max, Vector3& normal) const {
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
                return true;
            }
        }

        Vector3 point = ray(t);

        normal = (point - center).normalize();
        
        return true;
    }

    return false;
}