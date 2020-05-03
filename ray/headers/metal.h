//
//  metal.h
//  ray
//
//  Created by Marcelo de Mattos Nascimento on 20/03/20.
//  Copyright © 2020 Marcelo de Mattos Nascimento. All rights reserved.
//

#ifndef metal_h
#define metal_h
#include <utility>
#include "material.h"
#include <functional>
#include "vec_ops.h"
#include "random.h"
#include <stdexcept>

//using namespace std::placeholders;
class metal : public material {
    public:
        metal(const Vector3f& a, double f=0.0) : albedo(a), fuzz(f) {}
        
   
    
       virtual std::optional<material_hit> scatter(const ray& r_in, const hit_record& rec) const {
           const auto reflected = reflect(r_in.direction().normalized(), rec.normal);
           const auto scattered = ray(rec.p, reflected + fuzz* random_in_unit_sphere());
           if (scattered.direction().dot(rec.normal) > 0) {
               return material_hit  { albedo, scattered };
           }
           else return std::nullopt;
       }
private:
       
            
            
    const double fuzz;
    const Vector3f albedo;
};

#endif /* metal_h */
