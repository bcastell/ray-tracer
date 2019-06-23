#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include <cstdint>

#include "vector3.h"
#include "ray.h"
#include "shape.h"
#include "sphere.h"
#include "rgbcolor.h"
#include "scene.h"
#include "intersection.h"
#include "sampler.h"
#include "randomsampler.h"

RGBColor ray_color(const Ray& ray, const Scene& scene) {
    double t_min = 0.0;
    double t_max = std::numeric_limits<double>::max();

    Intersection intersection;

    if (scene.intersect(ray, t_min, t_max, intersection)) {
        Vector3 mapped_normal = 0.5 * intersection.normal + Vector3(0.5, 0.5, 0.5);

        return RGBColor(mapped_normal);
    }

    return RGBColor();
}

int main() {
    char magic_id[] = "P3";
    int img_width = 1024;
    int img_height = 768;
    int max_color = 255;

    std::cout << magic_id << "\n";
    std::cout << img_width << " " << img_height << "\n";
    std::cout << max_color << "\n";

    std::vector<std::shared_ptr<Shape>> objects = {
        std::shared_ptr<Shape>(new Sphere(Vector3(0.0, 0.0, -1.0), 0.5)),
        std::shared_ptr<Shape>(new Sphere(Vector3(0.0, -100.5, -1.0), 100.0))
    };

    Scene scene(objects);

    Vector3 camera_origin;

    double aspect_ratio = double(img_width) / img_height;

    double img_plane_width = 2.0 * aspect_ratio;
    double img_plane_height = 2.0;

    double camera_distance_to_img_plane = 1.0;

    Vector3 top_left_corner(-aspect_ratio, img_plane_height / 2.0, -camera_distance_to_img_plane);
    Vector3 u(img_plane_width, 0.0, 0.0);
    Vector3 v(0.0, -img_plane_height, 0.0);

    uint64_t rays_per_pixel = 32;

    std::shared_ptr<Sampler> sampler(new RandomSampler(rays_per_pixel));

    for (int y = 0; y < img_height; ++y) {
        for (int x = 0; x < img_width; ++x) {
            RGBColor pixel_color;

            sampler->sample_unit_square(Vector3(x, y, 0.0));

            for (uint64_t r = 0; r < rays_per_pixel; ++r) {
                Vector3 raster_space_sample = sampler->next_unit_square_sample();

                double x_offset = raster_space_sample.x / img_width;
                double y_offset = raster_space_sample.y / img_height;

                Vector3 screen_space_sample = top_left_corner + x_offset * u + y_offset * v;

                Ray camera_ray(camera_origin, screen_space_sample);

                pixel_color += ray_color(camera_ray, scene);
            }

            pixel_color /= rays_per_pixel;

            std::cout << pixel_color.normalize(max_color) << "\n";
        }
    }
}