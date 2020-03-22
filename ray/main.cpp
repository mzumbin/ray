//
//  main.cpp
//  ray
//
//  Created by Marcelo de Mattos Nascimento on 12/05/19.
//  Copyright © 2019 Marcelo de Mattos Nascimento. All rights reserved.
//

#include <iostream>
#include "ray.h"
#include <CImg.h>
#include "sphere.h"
#include "hittable_list.h"
#include "camera.h"
#include "random.h"
#include <memory>
#include "lambertian.h"
#include "metal.h"
using namespace cimg_library;
static const auto max_depht = 50;

Vector3f color(const ray& r, hittable_list& world, int depht) {
    // hit_record rec;
    if (auto hitO = world.hit(r, 0.001, MAXFLOAT)) {
        auto rec = hitO.value();
        auto scat_hit0 = rec.m->scatter(r,rec);
        if ( scat_hit0.has_value() && depht < max_depht){
            return scat_hit0->attenuation.cwiseProduct( color(scat_hit0->scattered, world, depht+1));
        }else{
            return Vector3f(0.,0.,0.);
        }
//        Vector3f target = rec.p + rec.normal + random_in_unit_sphere();
//        return 0.5 * color(ray(rec.p, target - rec.p), world);
    }
    else {
        Vector3f unit_direction = r.direction().normalized();
        float t = 0.5*(unit_direction.y() + 1.0);
        return (1.0-t)*Vector3f(1.0, 1.0, 1.0) + t*Vector3f(0.5, 0.7, 1.0);
    }
}

int main(int argc, const char * argv[]) {
    int nx = 800;
    int ny = 400;
    int ns = 200;
    CImg<unsigned char> visu(nx,ny,1,3,0);
    std::vector<hittable*>  list;
    list.emplace_back( new sphere(Vector3f(0,0,-1), 0.5, new lambertian(Vector3f(0.8, 0.3, 0.3))));
    list.emplace_back( new sphere(Vector3f(0,-100.5,-1), 100, new lambertian(Vector3f(0.8, 0.8, 0.0))));
    list.emplace_back( new sphere(Vector3f(1,0,-1), 0.5, new metal(Vector3f(0.8, 0.6, 0.2))));
    list.emplace_back( new sphere(Vector3f(-1,0,-1), 0.5, new metal(Vector3f(0.8, 0.8, 0.8))));
    hittable_list world = hittable_list(std::move(list));
    camera cam;
    
    
    cimg_forXY(visu,i,j) {
        Vector3f col(0.,0.,0.);
        for (int s = 0; s < ns; s++) {
            float u = float(i + random_double()) / float(nx);
            float v = float(j + random_double()) / float(ny);
            ray r = cam.get_ray(u, v);
            col += color(r, world, 0);
        }
        col /= float(ns);
        col = Vector3f( sqrt(col[0]), sqrt(col[1]), sqrt(col[2]) );
        int ir = int(255.99*col.x());
        int ig = int(255.99*col.y());
        int ib = int(255.99*col.z());
        
        visu(i,j) = ir;
        visu(i,j,0,1) = ig;
        visu(i,j,0,2) = ib;
    }
    
    visu.save("/Users/marcelo/Downloads/t.bmp");
    return 0;
    
}
