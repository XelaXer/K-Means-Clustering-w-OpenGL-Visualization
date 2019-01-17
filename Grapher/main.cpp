#include <freeglut.h>
#include <thread>
#include <iostream>
#include "glApp.h"

int main(int argc, char** argv) {
	const char* label = "K-Means Clustering Grapher";
	// GLUT Initialization
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearDepth(1.0f);
	// Run GLUT app containing Grapher app
	glApp app(label);
	app.run();
}