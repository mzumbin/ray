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
class sphere: public hittable  {
    public:
        sphere() {}
        sphere(Vector3f cen, float r) : center(cen), radius(r)  {};
        virtual std::optional<hit_record> hit(const ray& r, float tmin, float tmax) const;
        Vector3f center;
        float radius;
};

std::optional<hit_record> sphere::hit(const ray& r, float t_min, float t_max) const {
    Vector3f oc = r.origin() - center;
    float a = (r.direction().dot(r.direction()) );
    float b = oc.dot( r.direction());
    float c = oc.dot(oc)  - radius*radius;
    float discriminant = b*b - a*c;
    hit_record rec ;
    if (discriminant > 0) {
        float temp = (-b - sqrt(discriminant))/a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            return rec;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            auto t = temp;
            auto p = r.point_at_parameter(rec.t);
            auto normal = (rec.p - center) / radius;
            return hit_record{ t, p, normal};
        }
    }
    return std::nullopt;
}


#endif /* sphere_h */
