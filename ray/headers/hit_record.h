//
//  hit_record.h
//  ray
//
//  Created by Marcelo de Mattos Nascimento on 20/03/20.
//  Copyright © 2020 Marcelo de Mattos Nascimento. All rights reserved.
//

#ifndef hit_record_h
#define hit_record_h
//#include "material_scatter.h"
class material;
struct hit_record {
    float t;
    Vector3f p;
    Vector3f normal;
    material* material;
    bool front_face;

    
    
    //hit_record(const material& m): m(n) {};
   
};
inline hit_record build_hit_record(const ray& r, const Vector3f& outward_normal, const float& _t  , const Vector3f& _p, material* material) {
    const auto front_face = r.direction().dot(outward_normal) < 0;
    const auto normal = front_face ? outward_normal : - outward_normal;
    
    return hit_record { _t, _p, normal, material, front_face };
    
}
#endif /* hit_record_h */
