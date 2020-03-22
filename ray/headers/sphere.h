//
//  sphere.h
//  ray
//
//  Created by Marcelo de Mattos Nascimento on 16/02/20.
//  Copyright © 2020 Marcelo de Mattos Nascimento. All rights reserved.
//

#ifndef sphere_h
#define sphere_h
#include "hitable.h"
#include  <utility>
#include <iostream>

class sphere: public hittable  {
    public:
        //sphere() {}
        sphere(Vector3f cen, float r, material* m) : center(cen), radius(r) ,scater(m) {};
        virtual std::optional<hit_record> hit(const ray& r, float tmin, float tmax) const;
        Vector3f center;
        float radius;
        material* scater;
};

std::optional<hit_record> sphere::hit(const ray& r, float t_min, float t_max) const {
    const Vector3f oc = r.origin() - center;
    const float a = (r.direction().dot(r.direction()) );
    const float b = oc.dot( r.direction());
    const float c = oc.dot(oc)  - radius*radius;
    const float discriminant = b*b - a*c;
   
    if (discriminant > 0) {
        const auto firstRoot = (-b - sqrt(discriminant))/a;
        if (firstRoot < t_max && firstRoot > t_min) {
            const auto p = r.point_at_parameter(firstRoot);
            const auto normal = (p - center) / radius;
            return hit_record { firstRoot, p , normal , scater};
        }
        const auto secondRoot = (-b + sqrt(discriminant)) / a;
        if (secondRoot < t_max && secondRoot > t_min) {
            const auto p = r.point_at_parameter(firstRoot);
            const auto normal = (p - center) / radius;
            return hit_record { secondRoot, p , normal , scater};
        }
    }
    return std::nullopt;
}


#endif /* sphere_h */
