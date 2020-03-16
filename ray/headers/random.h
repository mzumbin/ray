//
//  random.h
//  ray
//
//  Created by Marcelo de Mattos Nascimento on 17/02/20.
//  Copyright © 2020 Marcelo de Mattos Nascimento. All rights reserved.
//

#ifndef random_h
#define random_h
#include <functional>
#include <random>
#include <Eigen/Dense>


using namespace Eigen;
inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    static std::function<double()> rand_generator =
      std::bind(distribution, generator);
    return rand_generator();
}


Vector3f random_in_unit_sphere() {
    Vector3f p;
    do {
        p = 2.0*Vector3f(random_double(), random_double(), random_double()) - Vector3f(1,1,1);
    } while (p.dot(p) >= 1.0);
    return p;
}
#endif /* random_h */
