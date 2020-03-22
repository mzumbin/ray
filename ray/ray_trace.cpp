/*****************************
 ray_trace.c

 This file contains skeleton code for the ray tracing
 assignment.  You need to write the code to ray trace
 the scene read in from the input file.
*******************************/

//#include "ray_trace.h"
//#include "read_input.h"
////extern void readSceneFile(char *filename);
//
///* the information read from the file */
////SceneInfo scene;
//
///* keep low while testing, raise to see high quality image */
//int win_size = 490;
//
///* to hold the color information */
//float **rbitmap, **gbitmap, **bbitmap;
//
///*
//*  rayTrace
//*  This is the function that raytraces the given scene.  It
//*  should calculate the color value of each pixel and draw
//*  it in the interface window.
//*/
//
//void rayTrace(void)
//{
//	int i, j;
//	float rcolor = 0.0;
//	float gcolor = 0.0;
//	float bcolor = 0.0;
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//    glClear(GL_COLOR_BUFFER_BIT);
//    // allocate memory for our local buffer
//	rbitmap = (float **)malloc(sizeof(float *) * win_size);
//	gbitmap = (float **)malloc(sizeof(float *) * win_size);
//	bbitmap = (float **)malloc(sizeof(float *) * win_size);
//
//	for(i=0; i<win_size; i++){
//		// print statement to help you keep track of progress
//		if(i % 10 == 0)
//			printf("Processing scanline %d\n", i);
//
//		// REMOVE THIS LINE! THIS IS ONLY TO HELP YOU ENSURE THAT SOMETHING IS BEING DRAWN!!
//		rcolor += 0.005;
//
//		// allocate memory for this row in our local buffer
//		rbitmap[i] = (float *)malloc(sizeof(float) * win_size);
//		gbitmap[i] = (float *)malloc(sizeof(float) * win_size);
//		bbitmap[i] = (float *)malloc(sizeof(float) * win_size);
//
//		for(j=0; j<win_size; j++){
//
//			// determine the world coordinate location of the pixel (i,j)
//			// and create the primary ray
//
//			// for each object, determine if the primary ray intersects
//			// the object; keep track of the nearest intersected object
//
//			// determine if the intersection point is in shadow for each
//			// of the light sources
//
//			// determine the illumination at the intersection point based
//			// on unoccluded light sources and ambient lighting
//
//			// set the color for the pixel in our local buffer
//			rbitmap[i][j] = rcolor;
//			gbitmap[i][j] = gcolor;
//			bbitmap[i][j] = bcolor;
//		}
//	}
//
//	// Now scale all the color values (if necessary)
//	for(i=0; i<win_size; i++){
//		for(j=0; j<win_size; j++){
//
//		}
//	}
//
//	// Now draw all the pixels
//	glBegin(GL_POINTS);
//	for(i=0; i<win_size; i++){
//		for(j=0; j<win_size; j++){
//			glColor3f(rbitmap[i][j], gbitmap[i][j], bbitmap[i][j]);
//			glVertex2i(i, j);
//		}
//	}
//	glEnd();
//	glFlush();
//}
//
//void changeSize(int w, int h) {
//
//    // Prevent a divide by zero, when window is too short
//    // (you cant make a window of zero width).
//    //win_size=w;
//    //gluOrtho2D(0.0, win_size, 0.0, win_size);
//    //win_size = 500-1;
//    //gluOrtho2D(0.0, win_size, 0.0, win_size);
//   glutReshapeWindow(win_size, win_size);
//}
//
///*
//*	Main function.  Reads in the scene information,
//*	places it in data structures, and creates an interface window.
//*/
//
//int main0(int argc, char **argv)
//{
//	/* initialize */
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
//
//	/* read input */
//	readSceneFile("/Users/marcelo/Downloads/ray_trace/scene1.txt");
//
//	/* create the interface window */
//
//    glutInitWindowSize(win_size, win_size);
//	glutCreateWindow("Ray Tracing");
//	gluOrtho2D(0.0, win_size, 0.0, win_size);
//    //glutReshapeWindow(win_size, win_size);
//	/* set the display function */
//	glutDisplayFunc(rayTrace);
//   // glutReshapeFunc(changeSize);
//    //glutIdleFunc(rayTrace);
//    /* enter the main loop */
//	glutMainLoop();
//    return 0;
//}

