//
//  material_func.h
//  ray
//
//  Created by Marcelo de Mattos Nascimento on 20/03/20.
//  Copyright © 2020 Marcelo de Mattos Nascimento. All rights reserved.
//

#ifndef material_func_h
#define material_func_h
//#include "hit_record.h"
#include "material_hit.h"
#include "ray.h"
#include <functional>
#include <optional>
class hit_record;
using  material_scatter = std::function<std::optional<material_hit> (const ray&, const hit_record&)>;
#endif /* material_func_h */
