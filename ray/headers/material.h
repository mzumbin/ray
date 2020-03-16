//
//  material.h
//  ray
//
//  Created by Marcelo de Mattos Nascimento on 12/03/20.
//  Copyright © 2020 Marcelo de Mattos Nascimento. All rights reserved.
//

#ifndef material_h
#define material_h

#include <tuple>
#include <optional>
#include "ray.h"


struct material_hit {
    Vector3f attenuation,
    ray scattered
};
class material  {
    public:
        virtual std::optional<material_hit> scatter(
            const ray& r_in, const hit_record& rec) const = 0;
};

#endif /* material_h */
