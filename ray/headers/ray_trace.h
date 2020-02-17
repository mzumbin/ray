#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

//#define MAX_LIGHTS	3
//#define MAX_POLYS	10
//#define MAX_SPHERES	5
//
//typedef struct{
//	float x_pos;
//	float y_pos;
//	float z_pos;
//	float red;
//	float green;
//	float blue;
//} Light;
//
//typedef struct{
//	float x_center;
//	float y_center;
//	float z_center;
//	float radius;
//	float red;
//	float green;
//	float blue;
//} Sphere;
//
//typedef struct{
//	float x;
//	float y;
//	float z;
//} Vertex;
//
//typedef struct{
//	int no_vertices;
//	Vertex *vertices;
//	float red;
//	float green;
//	float blue;
//} Poly;
//
//typedef struct{
//	float view_z;
//	int no_lights;
//	Light lights[MAX_LIGHTS];
//	int no_spheres;
//	Sphere spheres[MAX_SPHERES];
//	int no_polygons;
//	Poly polygons[MAX_POLYS];
//} SceneInfo;
