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
#endif /* vec_ops_h */
