#ifndef RGBCOLOR_H
#define RGBCOLOR_H

#include <iostream>

#include "vector3.h"

class RGBColor {
    public:
        RGBColor();
        RGBColor(const Vector3& color);
        RGBColor(const RGBColor& rgb);

        RGBColor& operator=(const RGBColor& rgb);

        RGBColor operator+(const RGBColor& rgb) const;
        RGBColor operator-(const RGBColor& rgb) const;
        RGBColor operator*(const RGBColor& rgb) const;
        RGBColor operator*(double scalar) const;
        RGBColor operator/(double scalar) const;

        RGBColor& operator+=(const RGBColor& rgb);
        RGBColor& operator-=(const RGBColor& rgb);
        RGBColor& operator*=(const RGBColor& rgb);
        RGBColor& operator*=(double scalar);
        RGBColor& operator/=(double scalar);

        bool operator==(const RGBColor& rgb) const;
        bool operator!=(const RGBColor& rgb) const;

        RGBColor normalize(int max_color) const;

        friend RGBColor operator*(double scalar, const RGBColor& rgb);
        friend std::ostream& operator<<(std::ostream& os, const RGBColor& rgb);

    private:
        RGBColor& truncate();

        Vector3 color;
};

#endif