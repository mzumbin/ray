//
//  camera.h
//  ray
//
//  Created by Marcelo de Mattos Nascimento on 17/02/20.
//  Copyright © 2020 Marcelo de Mattos Nascimento. All rights reserved.
//

#ifndef camera_h
#define camera_h
#include "ray.h"
class camera {
    public:
        camera() {
            lower_left_corner = Vector3f(-2.0, -1.0, -1.0);
            horizontal = Vector3f(4.0, 0.0, 0.0);
            vertical = Vector3f(0.0, -2.0, 0.0);
            higher_left_corner = Vector3f(-2.0, 1.0, -1.0);
            origin = Vector3f(0.0, 0.0, 0.0);
        }
        ray get_ray(float u, float v) {
            return ray(origin,
                       higher_left_corner + u*horizontal + v*vertical - origin);
        }
    private :
        Vector3f origin;
        Vector3f lower_left_corner;
        Vector3f horizontal;
        Vector3f vertical;
        Vector3f higher_left_corner;
};
#endif /* camera_h */
