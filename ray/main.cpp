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


using namespace cimg_library;


float hit_sphere(const Vector3f& center, float radius, const ray& r) {
    Vector3f oc = r.origin() - center;
    float a = r.direction().dot( r.direction());
    float b = 2.0 * oc.dot( r.direction());
    float c = oc.dot( oc) - radius*radius;
    float discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        return -1.0;
    }
    else {
        return (-b - sqrt(discriminant) ) / (2.0*a);
    }
}

Vector3f color(const ray& r) {
    float t = hit_sphere(Vector3f(0,0,-1), 0.5, r);
    if (t > 0.0) {
        auto N = (r.point_at_parameter(t) - Vector3f(0,0,-1)).normalized();
        return 0.5*Vector3f(N.x()+1, N.y()+1, N.z()+1);
    }
    auto unit_direction = (r.direction()).normalized();
    t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*Vector3f(1.0, 1.0, 1.0) + t*Vector3f(0.5, 0.7, 1.0);
}
int main(int argc, const char * argv[]) {
    int nx = 200;
    int ny = 100;
    CImg<unsigned char> visu(nx,ny,1,3,0);
    
    Vector3f higher_left_corner(-2.0, 1.0, -1.0);
    Vector3f horizontal(4.0, 0.0, 0.0);
    Vector3f vertical(0.0, -2.0, 0.0);
    Vector3f origin(0.0, 0.0, 0.0);
    cimg_forXY(visu,i,j) {
        
   double u = double(i) / double(nx);
   double v = double(j) / double(ny);
   ray r(origin, higher_left_corner + u*horizontal + v*vertical);
   Vector3f col = color(r);
   int ir = int(255.99*col.x());
   int ig = int(255.99*col.y());
   int ib = int(255.99*col.z());

        visu(i,j) = ir;
        visu(i,j,0,1) =ig;
        visu(i,j,0,2)=ib;
    }
   
    visu.save("/Users/marcelo/Downloads/t.bmp");
    return 0;
    
}
