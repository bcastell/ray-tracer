#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <cmath>

class Vector3 {
    public:
        Vector3();
        Vector3(double x, double y, double z);
        Vector3(const Vector3& vec3);

        Vector3& operator=(const Vector3& vec3);

        Vector3 operator+(const Vector3& vec3) const;
        Vector3 operator-(const Vector3& vec3) const;
        Vector3 operator*(const Vector3& vec3) const;
        Vector3 operator*(double scalar) const;
        Vector3 operator/(double scalar) const;

        Vector3& operator+=(const Vector3& vec3);
        Vector3& operator-=(const Vector3& vec3);
        Vector3& operator*=(const Vector3& vec3);
        Vector3& operator*=(double scalar);
        Vector3& operator/=(double scalar);

        Vector3 operator+() const;
        Vector3 operator-() const;

        bool operator==(const Vector3& vec3) const;
        bool operator!=(const Vector3& vec3) const;

        double length() const;
        double squared_length() const;
        double dot(const Vector3& vec3) const;
        Vector3 normalize() const;

        friend Vector3 operator*(double scalar, const Vector3& vec3);
        friend std::ostream& operator<<(std::ostream& os, const Vector3& vec3);

        double x;
        double y;
        double z;
};

#endif