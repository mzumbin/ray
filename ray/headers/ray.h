//
//  ray.h
//  ray
//
//  Created by Marcelo de Mattos Nascimento on 09/02/20.
//  Copyright © 2020 Marcelo de Mattos Nascimento. All rights reserved.
//

#ifndef ray_h
#define ray_h
#include <Eigen/Dense>


using namespace Eigen;
class ray
{
    public:
        ray() {}
        ray(const Vector3f& a, const Vector3f& b) { A = a; B = b; }
        Vector3f origin() const       { return A; }
        Vector3f direction() const    { return B; }
        Vector3f point_at_parameter(float t) const { return A + t*B; }

        Vector3f A;
        Vector3f B;
};

#endif /* ray_h */
