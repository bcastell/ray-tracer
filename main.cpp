#include <iostream>

#include "vector3.h"
#include "ray.h"
#include "sphere.h"
#include "rgbcolor.h"

RGBColor ray_color(const Ray& ray) {
    Sphere sphere(Vector3(0.0, 0.0, -1.0), 0.5);

    if (sphere.intersect(ray)) {
        return RGBColor(Vector3(1.0, 0.0, 0.0));
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

    double aspect_ratio = double(img_width) / img_height;

    Vector3 camera_origin;

    double camera_distance_to_img_plane = 1.0;

    double img_plane_width = 2.0 * aspect_ratio;
    double img_plane_height = 2.0;

    Vector3 top_left_corner(-aspect_ratio, img_plane_height / 2.0, -camera_distance_to_img_plane);
    Vector3 u(img_plane_width, 0.0, 0.0);
    Vector3 v(0.0, -img_plane_height, 0.0);

    for (int y = 0; y < img_height; ++y) {
        double y_offset = (y + 0.5) / img_height;

        for (int x = 0; x < img_width; ++x) {
            double x_offset = (x + 0.5) / img_width;

            Vector3 px_center = top_left_corner + x_offset * u + y_offset * v; 

            Ray camera_ray(camera_origin, px_center);

            RGBColor px_color = ray_color(camera_ray);

            std::cout << px_color.normalize(max_color) << "\n";
        }
    }
}