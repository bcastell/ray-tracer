#include "scene.h"

Scene::Scene(const std::vector<std::shared_ptr<Shape>>& objects) : objects(objects) {}

bool Scene::intersect(const Ray& ray, double t_min, double t_max, Intersection& intersection) const {
    bool intersected = false;
    double t_closest = t_max;

    for (auto& object : objects) {
        Intersection object_intersection;

        if (object->intersect(ray, t_min, t_closest, object_intersection)) {
            intersected = true;
            intersection = object_intersection;

            if (object_intersection.t < t_closest) {
                t_closest = object_intersection.t;
            }
        }
    }

    return intersected;
}