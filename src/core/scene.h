#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>

#include "shape.h"
#include "ray.h"
#include "intersection.h"

class Scene {
    public:
        Scene(const std::vector<std::shared_ptr<Shape>>& objects);

        bool intersect(const Ray& ray, double t_min, double t_max, Intersection& intersection) const;

    private:
        std::vector<std::shared_ptr<Shape>> objects;
};

#endif