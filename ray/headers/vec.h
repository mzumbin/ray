//
//  vec.h
//  ray
//
//  Created by Marcelo de Mattos Nascimento on 12/05/19.
//  Copyright © 2019 Marcelo de Mattos Nascimento. All rights reserved.
//

#ifndef vec_h
#define vec_h
#include <array>
#include <type_traits>
#include <cmath>
#include <Eigen/Dense>
template<class F>
class vec3{
public:
    vec3(){
        static_assert(std::is_floating_point<F>::value, "Integral required.");
         e = {0,0,0};
    }
    vec3( F e0, F e1, F e2){
        static_assert(std::is_floating_point<F>::value, "Integral required.");
       e = {e0,e1,e2};
    }
    inline F x() const { return e[0];}
    inline F y() const { return e[1];}
    inline F z() const { return e[2];}
    
    inline F r() const { return e[0];}
    inline F g() const { return e[1];}
    inline F b() const { return e[2];}
    
    inline vec3& operator+() const { return *this;}
    inline vec3& operator-() const { return vec3( -e[0], -e[1],-e[2] );}
    
    inline F operator[](int i )const { return e[i]; }
    inline F& operator[](int i){ return e[i]; }
    
    inline vec3& operator*=(const float t);
    inline vec3& operator/=(const float t);
    
    inline float length() const { return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]); }
    inline float squared_length() const { return e[0]*e[0] + e[1]*e[1] + e[2]*e[2]; }
    inline void make_unit_vector(){
        float k = 1.0 / sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
        e[0] *= k; e[1] *= k; e[2] *= k;
    }
    inline vec3& operator+=(const vec3 &v){
        e[0]  += v.e[0];
        e[1]  += v.e[1];
        e[2]  += v.e[2];
        return *this;
    }
    
    inline vec3& operator-=(const vec3& v) {
        e[0]  -= v.e[0];
        e[1]  -= v.e[1];
        e[2]  -= v.e[2];
        return *this;
    }
    
    inline vec3& operator*=(const vec3 &v){
        e[0]  *= v.e[0];
        e[1]  *= v.e[1];
        e[2]  *= v.e[2];
        return *this;
    }
    
    inline vec3& operator/=(const vec3 &v){
        e[0]  /= v.e[0];
        e[1]  /= v.e[1];
        e[2]  /= v.e[2];
        return *this;
    }
    
    inline vec3& operator*=(const F t) {
        e[0]  *= t;
        e[1]  *= t;
        e[2]  *= t;
        return *this;
    }
    
    inline vec3& operator/=(const F t) {
        float k = 1.0/t;
        
        e[0]  *= k;
        e[1]  *= k;
        e[2]  *= k;
        return *this;
    }
    std::array<F, 3> e;
    
};
template<typename F>
inline std::istream& operator>>(std::istream &is, vec3<F> &t) {
    is >> t.e[0] >> t.e[1] >> t.e[2];
    return is;
}

template<typename F> inline std::ostream& operator<<(std::ostream &os, const vec3<F> &t) {
    os << t.e[0] << " " << t.e[1] << " " << t.e[2];
    return os;
}


template<typename F> inline vec3<F> operator+(const vec3<F> &v1, const vec3<F> &v2) {
    return vec3<F>(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

template<typename F> inline vec3<F> operator-(const vec3<F> &v1, const vec3<F> &v2) {
    return vec3<F>(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

template<typename F> inline vec3<F> operator*(const vec3<F> &v1, const vec3<F> &v2) {
    return vec3<F>(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

template<typename F> inline vec3<F> operator/(const vec3<F> &v1, const vec3<F> &v2) {
    return vec3<F>(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

template<typename F> inline vec3<F> operator*(F t, const vec3<F> &v) {
    return vec3<F>(t*v.x(), t*v.y(), t*v.z());
}

template<typename F> inline vec3<F> operator/(vec3<F> v, F t) {
    return vec3<F>(v.e[0]/t, v.e[1]/t, v.e[2]/t);
}

template<typename F> inline vec3<F> operator*(const vec3<F> &v, F t) {
    return vec3<F>(t*v.x(), t*v.y(), t*v.z());
}

template<typename F> inline float dot(const vec3<F> &v1, const vec3<F> &v2) {
    return v1.e[0] *v2.e[0] + v1.e[1] *v2.e[1]  + v1.e[2] *v2.e[2];
}

template<typename F> inline vec3<F> cross(const vec3<F> &v1, const vec3<F> &v2) {
    return vec3<F>( (v1.e[1]*v2.e[2] - v1.e[2]*v2.e[1]),
                (-(v1.e[0]*v2.e[2] - v1.e[2]*v2.e[0])),
                (v1.e[0]*v2.e[1] - v1.e[1]*v2.e[0]));
}


template<typename F> inline vec3<F> unit_vector(vec3<F> v) {
    return v / v.length();
}

typedef  vec3<double> ved3_d;
#endif /* vec_h */
