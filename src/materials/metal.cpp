#include "metal.h"

Metal::Metal(const Vector3& albedo, double fuzziness) : albedo(albedo), fuzziness(fuzziness) {}

Metal::~Metal() {}

bool Metal::scatter(const Ray& incident_ray, const Intersection& intersection, Vector3& attenuation, Ray& scattered_ray) const {
    Vector3 scattered_direction = reflect(incident_ray.direction.normalize(), intersection.normal);

    scattered_ray = Ray(intersection.point, scattered_direction + fuzziness * rejection_sample_unit_sphere());

    attenuation = albedo;

    return scattered_ray.direction.dot(intersection.normal) > 0.0;
}

Vector3 Metal::reflect(const Vector3& incident_ray_direction, const Vector3& normal) const {
    return incident_ray_direction - 2.0 * incident_ray_direction.dot(normal) * normal;
}