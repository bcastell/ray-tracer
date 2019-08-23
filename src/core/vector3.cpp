#include "vector3.h"

Vector3::Vector3() : x(0.0), y(0.0), z(0.0) {}

Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

Vector3::Vector3(const Vector3& vec3) : x(vec3.x), y(vec3.y), z(vec3.z) {}

Vector3& Vector3::operator=(const Vector3& vec3) {
    x = vec3.x;
    y = vec3.y;
    z = vec3.z;

    return *this;
}

Vector3 Vector3::operator+(const Vector3& vec3) const {
    return Vector3(x + vec3.x, y + vec3.y, z + vec3.z);
}

Vector3 Vector3::operator-(const Vector3& vec3) const {
    return Vector3(x - vec3.x, y - vec3.y, z - vec3.z);
}

Vector3 Vector3::operator*(const Vector3& vec3) const {
    return Vector3(x * vec3.x, y * vec3.y, z * vec3.z);
}

Vector3 Vector3::operator*(double scalar) const {
    return Vector3(scalar * x, scalar * y, scalar * z);
}

Vector3 Vector3::operator/(double scalar) const {
    return Vector3(x / scalar, y / scalar, z / scalar);
}

Vector3& Vector3::operator+=(const Vector3& vec3) {
    x += vec3.x;
    y += vec3.y;
    z += vec3.z;

    return *this;
}

Vector3& Vector3::operator-=(const Vector3& vec3) {
    x -= vec3.x;
    y -= vec3.y;
    z -= vec3.z;

    return *this;
}

Vector3& Vector3::operator*=(const Vector3& vec3) {
    x *= vec3.x;
    y *= vec3.y;
    z *= vec3.z;

    return *this;
}

Vector3& Vector3::operator*=(double scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

Vector3& Vector3::operator/=(double scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;

    return *this;
}

Vector3 Vector3::operator+() const {
    return *this;
}

Vector3 Vector3::operator-() const {
    return *this * -1.0;
}

bool Vector3::operator==(const Vector3& vec3) const {
    return x == vec3.x && y == vec3.y && z == vec3.z;
}

bool Vector3::operator!=(const Vector3& vec3) const {
    return x != vec3.x || y != vec3.y || z != vec3.z;
}

double Vector3::length() const {
    return sqrt(x * x + y * y + z * z);
}

double Vector3::squared_length() const {
    return length() * length();
}

double Vector3::dot(const Vector3& vec3) const {
    return x * vec3.x + y * vec3.y + z * vec3.z;
}

Vector3 Vector3::normalize() const {
    return *this / length();
}

Vector3 operator*(double scalar, const Vector3& vec3) {
    return vec3 * scalar;
}

std::ostream& operator<<(std::ostream& os, const Vector3& vec3) {
    os << vec3.x << " " << vec3.y << " " << vec3.z;

    return os;
}