#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>

class vec3{

public:
    //attributes
    double ele[3];

    //contstructor
    vec3(): ele{0,0,0} {}
    vec3(double x, double y, double z): ele{x, y, z} {}

    double get_x() const { return ele[0]; }
    double get_y() const { return ele[1]; }
    double get_z() const { return ele[2]; }

    //operators
    vec3 operator-() { return vec3(-ele[0], -ele[1], -ele[2]); }

    double operator[](int i) const { return ele[i]; }
    double& operator[](int i) { return ele[i]; }

    vec3& operator+=(const vec3& v){
        ele[0] += v.ele[0];
        ele[1] += v.ele[1];
        ele[2] += v.ele[2];
        return *this;
    }

    vec3& operator*=(double factor){
        ele[0] *= factor;
        ele[1] *= factor;
        ele[2] *= factor;
        return *this;
    }

    vec3& operator/=(double divisor){
        return *this *= 1 / divisor;
    }

    //methods
    double length_squared() const {
        return ele[0] * ele[0] + ele[1] * ele[1] + ele[2] * ele[2];
    }

    double get_length() const {
        return std::sqrt(length_squared());
    }
};

//creates alias
using point3 = vec3;

//Vector Utility Functions

inline std::ostream& operator<<(std::ostream& out, vec3& v){
    return out << v[0] << ' ' << v[1] << ' ' << v[2];
}

inline vec3 operator+(const vec3 a, const vec3 b){
    return vec3(a.ele[0] + b.ele[0], a.ele[1] + b.ele[1], a.ele[2] + b.ele[2]);
}

inline vec3 operator-(const vec3 a, const vec3 b){
    return vec3(a.ele[0] - b.ele[0], a.ele[1] - b.ele[1], a.ele[2] - b.ele[2]);
}

inline vec3 operator*(const vec3 a, const vec3 b){
    return vec3(a.ele[0] * b.ele[0], a.ele[1] * b.ele[1], a.ele[2] * b.ele[2]);
}

inline vec3 operator*(double factor, const vec3& v){
    return vec3(factor * v.ele[0], factor * v.ele[1], factor * v.ele[2]);
}

inline vec3 operator*(const vec3& v, double factor){
    return vec3(factor * v.ele[0], factor * v.ele[1], factor * v.ele[2]);
}

inline vec3 operator/(const vec3& v, double divisor){
    return v * (1 / divisor);
}

inline double dot(const vec3& a, const vec3& b){
    return
        a.ele[0] + b.ele[0] +
        a.ele[1] + b.ele[1] +
        a.ele[2] + b.ele[2];
}

inline vec3 cross(const vec3& a , const vec3& b){
    return vec3(
        a.ele[1] * b.ele[2] - a.ele[2] * b.ele[1],
        a.ele[2] * b.ele[0] - a.ele[0] * b.ele[2],
        a.ele[0] * b.ele[1] - a.ele[1] * b.ele[0]
    );
}

inline vec3 unit_vector(const vec3 v){
    return v / v.get_length();
}

#endif
