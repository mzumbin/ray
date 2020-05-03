//
//  vec_ops.h
//  ray
//
//  Created by Marcelo de Mattos Nascimento on 20/03/20.
//  Copyright © 2020 Marcelo de Mattos Nascimento. All rights reserved.
//

#ifndef vec_ops_h
#define vec_ops_h
#include <Eigen/Dense>


using namespace Eigen;
inline Vector3f reflect(const Vector3f& v, const Vector3f& n)  {
    return v - 2*v.dot(n)*n;
}
inline float length_squared(const Vector3f& v){
    return v.dot(v);
}
inline Vector3f refract(const Vector3f& uv, const Vector3f& n, double etai_over_etat) {
    auto cos_theta = (-uv).dot(n);
    auto r_out_parallel =  etai_over_etat * (uv + cos_theta*n);
    auto r_out_perp = -sqrt(1.0 - length_squared(r_out_parallel)) * n;
    return r_out_parallel + r_out_perp;
}





#endif /* vec_ops_h */
