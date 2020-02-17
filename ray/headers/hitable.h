//
//  hitable.h
//  ray
//
//  Created by Marcelo de Mattos Nascimento on 16/02/20.
//  Copyright © 2020 Marcelo de Mattos Nascimento. All rights reserved.
//

#ifndef hitable_h
#define hitable_h
#include <optional>
#include <functional>
#include "ray.h"
struct hit_record {
    float t;
    Vector3f p;
    Vector3f normal;
};

class hittable  {
    public:
        virtual std::optional<hit_record>  hit(
            const ray& r, float t_min, float t_max) const = 0;
};


#endif /* hitable_h */
