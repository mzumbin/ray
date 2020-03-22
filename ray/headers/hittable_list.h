//
//  hittable_list.h
//  ray
//
//  Created by Marcelo de Mattos Nascimento on 16/02/20.
//  Copyright © 2020 Marcelo de Mattos Nascimento. All rights reserved.
//

#ifndef hittable_list_h
#define hittable_list_h
#include "hitable.h"
#include <vector>
#include <utility>
class hittable_list: public hittable {
    public:
        hittable_list() {}
        hittable_list(std::vector<hittable*> &&l) {_hittable_list = std::move(l); }

        std::optional<hit_record> hit(const ray& r, float t_min, float t_max) const {

            std::optional<hit_record> temp_rec = std::nullopt ;
            bool hit_anything = false;
            double closest_so_far = t_max;
            for (auto& hitable : _hittable_list) {
                if (auto hit_recO = hitable->hit(r, t_min, closest_so_far)) {
                    hit_anything = true;
                    closest_so_far = hit_recO->t;
                    temp_rec = std::move(hit_recO);
                }
            }
            if (hit_anything){
                return temp_rec;
            }
            else return std::nullopt;
        }
        std::vector<hittable*> _hittable_list;
        
};



#endif /* hittable_list_h */
