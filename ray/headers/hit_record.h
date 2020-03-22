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
    material* m;
    
    //hit_record(const material& m): m(n) {};
   
};

#endif /* hit_record_h */
