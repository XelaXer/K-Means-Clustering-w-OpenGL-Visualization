#include <freeglut.h>
#include <iostream>
#include "glApp.h"

// To create static instance for glut functions
static glApp* currentInstance;
extern "C"
void displayCallback() {
	currentInstance->render();
}

void keyboardCallback(unsigned char key, int x, int y) {
	currentInstance->keypress(key);
}

void mouseCallback(int b, int s, int x, int y) {
	float mx = (float)x;
	float my = (float)y;
	currentInstance->windowToScene(mx, my);
	std::cout << "Mouse Coordinates" << std::endl;
	std::cout << x << " " << y << std::endl;

	// Determine button and state and call appropriate handler
	if (b == 0) {
		// Left click
		if (s == 0) {
			// Left down
			//currentInstance->mouseDown(mx, my);
		} else {
			// Left up
			//currentInstance->mouseUp(mx, my);
		}
	} else {
		// Right click
		if (s == 0) {
			// Right down
			//currentInstance->mouseRightDown(mx, my);
		} else {
			// Right up
			//currentInstance->mouseRightUp(mx, my);
		}
	}
}
// End of static instance code

void resize(int width, int height) {
	if (height == 0) {
		height = 1;
	}
	float ratio = width * 1.0 / height;
	glMatrixMode(GL_PROJECTION); // Use the Projection Matrix
	glLoadIdentity(); // Reset Matrix
	glViewport(0, 0, width, height); // Set the viewport to be the entire window
	gluPerspective(45, ratio, 1, 100); // Set the correct perspective
	glMatrixMode(GL_MODELVIEW); // Get Back to the Modelview
}

glApp::glApp(const char* label) {
	currentInstance = this;
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow(label);
}

void glApp::run() {
	glutKeyboardFunc(keyboardCallback);
	glutMouseFunc(mouseCallback);
	glutDisplayFunc(displayCallback);
	glutIdleFunc(displayCallback);
	glutReshapeFunc(resize);
	glutMainLoop();
	
}

void glApp::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	g.draw();
	glFlush();
	glutSwapBuffers();
}

void glApp::mouse() {
	glutMouseFunc(mouseCallback);
}

void glApp::keypress(unsigned char key) {
	if (key == 119) {
		g.runAlgorithmIteration();
	}
	if (key == 97) {
		//g.runAlgorithm();
	}
}

void glApp::windowToScene(float& x, float &y) {
	// Converting window coordinates [0..width] x [0..height] to [-1..1] x [-1..1]
	x = (2.0f*(x / float(width))) - 1.0f;
	y = 1.0f - (2.0f*(y / float(height)));
	// Take care of issue in Windows where y coordinate is a little off
#if defined WIN32
	y -= 0.03;
#endif
}

