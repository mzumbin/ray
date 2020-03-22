//
//  lambertian.h
//  ray
//
//  Created by Marcelo de Mattos Nascimento on 16/03/20.
//  Copyright © 2020 Marcelo de Mattos Nascimento. All rights reserved.
//

#ifndef lambertian_h
#define lambertian_h
#include <utility>
#include "material.h"
#include <functional>
using namespace std::placeholders;
class lambertian : public material {
    public:
    
     lambertian(const Vector3f& a) : albedo(a) {}
     virtual  std::optional<material_hit> scatter(const ray& r_in, const hit_record& rec) const {
            const Vector3f target = rec.p + rec.normal + random_in_unit_sphere();
            const auto scattered = ray(rec.p, target-rec.p);
            return material_hit{ albedo , scattered };
        }
    material_scatter getMaterialFunc() {
        return std::bind(&lambertian::scatter,this, _1, _2);
    }
    
    private :
        const Vector3f albedo;
};

#endif /* lambertian_h */
