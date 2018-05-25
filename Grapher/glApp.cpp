#include <freeglut.h>
#include "glApp.h"

// To create static instance for glutDisplayFunc
static glApp* currentInstance;
extern "C"
void callback() {
	currentInstance->render();
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
	glutDisplayFunc(callback);
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