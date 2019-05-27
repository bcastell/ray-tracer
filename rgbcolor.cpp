#include "rgbcolor.h"

RGBColor::RGBColor() : color(Vector3(0.0, 0.0, 0.0)) {}

RGBColor::RGBColor(const Vector3& color) : color(color) {}

RGBColor::RGBColor(const RGBColor& rgb) : color(rgb.color) {}

RGBColor& RGBColor::operator=(const RGBColor& rgb) {
    color = rgb.color;

    return *this;
}

RGBColor RGBColor::operator+(const RGBColor& rgb) const {
    return RGBColor(color + rgb.color);
}

RGBColor RGBColor::operator-(const RGBColor& rgb) const {
    return RGBColor(color - rgb.color);
}

RGBColor RGBColor::operator*(const RGBColor& rgb) const {
    return RGBColor(color * rgb.color);
}

RGBColor RGBColor::operator*(double scalar) const {
    return RGBColor(color * scalar);
}

RGBColor RGBColor::operator/(double scalar) const {
    return RGBColor(color / scalar);
}

RGBColor& RGBColor::operator+=(const RGBColor& rgb) {
    color += rgb.color;

    return *this;
}

RGBColor& RGBColor::operator-=(const RGBColor& rgb) {
    color -= rgb.color;

    return *this;
}

RGBColor& RGBColor::operator*=(const RGBColor& rgb) {
    color *= rgb.color;

    return *this;
}

RGBColor& RGBColor::operator*=(double scalar) {
    color *= scalar;

    return *this;
}

RGBColor& RGBColor::operator/=(double scalar) {
    color /= scalar;

    return *this;
}

bool RGBColor::operator==(const RGBColor& rgb) const {
    return color == rgb.color;
}

bool RGBColor::operator!=(const RGBColor& rgb) const {
    return color != rgb.color;
}

RGBColor RGBColor::normalize(int max_color) const {
    RGBColor rgb = *this * max_color;

    return rgb.truncate();
}

RGBColor operator*(double scalar, const RGBColor& rgb) {
    return rgb * scalar;
}

std::ostream& operator<<(std::ostream& os, const RGBColor& rgb) {
    os << rgb.color;

    return os;
}

RGBColor& RGBColor::truncate() {
    color.x = (int) color.x;
    color.y = (int) color.y;
    color.z = (int) color.z;

    return *this;
}