//
//  dieletric.h
//  ray
//
//  Created by Marcelo de Mattos Nascimento on 02/05/20.
//  Copyright © 2020 Marcelo de Mattos Nascimento. All rights reserved.
//

#ifndef dieletric_h
#define dieletric_h
#include "ray.h"
#include "material.h"
#include "vec_ops.h"
#include <algorithm>
class dielectric : public material {
    public:
    
    dielectric(double ri) : ref_idx(ri) {}

        
    virtual std::optional<material_hit> scatter(const ray& r_in, const hit_record& rec) const{
        const auto attenuation = Vector3f(1.0, 1.0, 1.0);
        const double etai_over_etat = (rec.front_face) ? (1.0 / ref_idx) : (ref_idx);

        const Vector3f unit_direction = r_in.direction().normalized();
        double cos_theta = std::min( (-unit_direction).dot(rec.normal), 1.0f);
        double sin_theta = sqrt(1.0 - cos_theta*cos_theta);
       
       if (etai_over_etat * sin_theta > 1.0 ) {
           const auto reflected = reflect(unit_direction, rec.normal);
           const auto scattered = ray(rec.p, reflected);
           return material_hit{ attenuation,scattered };
       }
       double reflect_prob = schlick(cos_theta, etai_over_etat);
       if (random_double() < reflect_prob)
       {
           const auto reflected = reflect(unit_direction, rec.normal);
           const auto scattered = ray(rec.p, reflected);
           return material_hit{ attenuation,scattered };
           
       }
       const Vector3f refracted = refract(unit_direction, rec.normal, etai_over_etat);
       const auto scattered = ray(rec.p, refracted);
       return material_hit{ attenuation, scattered };
    }
    
private:
    double schlick(double cosine, double ref_idx) const {
        auto r0 = (1 - ref_idx) / (1 + ref_idx);
        r0 = r0*r0;
        return r0 + (1 - r0)*pow((1 - cosine),5);
    }

        double ref_idx;
};

#endif /* dieletric_h */
