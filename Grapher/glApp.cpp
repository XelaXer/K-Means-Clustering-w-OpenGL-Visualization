#include <freeglut.h>
#include <iostream>
#include <thread>
#include "glApp.h"

// To create static instance for glut functions
static glApp* currentInstance;
extern "C"
void displayCallback() {
	currentInstance->render();
}
void keyboardCallback(unsigned char const key, int x, int y) {
	currentInstance->keypress(key);
}
void mouseButtonCallback(int button, int state, int x, int y) {
	currentInstance->mouseButton(button, state, x,y);
}
void mouseMoveCallback(int x, int y) {
	currentInstance->mouseMove(x, y);
}
void idleCallback() {
	currentInstance->idle();
}
// End of static instance code



//void mouseCallback(int b, int s, int x, int y) {
//
//	float mx = (float)x;
//	float my = (float)y;
//	currentInstance->windowToScene(mx, my);
//	std::cout << "Mouse Coordinates" << std::endl;
//	std::cout << x << " " << y << std::endl;
//
//	// Determine button and state and call appropriate handler
//	if (b == 0) {
//		// Left click
//		if (s == 0) {
//			// Left down
//			//currentInstance->mouseDown(mx, my);
//		} else {
//			// Left up
//			//currentInstance->mouseUp(mx, my);
//		}
//	} else {
//		// Right click
//		if (s == 0) {
//			// Right down
//			//currentInstance->mouseRightDown(mx, my);
//		} else {
//			// Right up
//			//currentInstance->mouseRightUp(mx, my);
//		}
//	}
//}




void resize(int width, int height) {
	if (height == 0) {
		height = 1;
	}
	float ratio = width * 1.0 / height;
	glMatrixMode(GL_PROJECTION); // Use the Projection Matrix
	glLoadIdentity(); // Reset Matrix
	glViewport(0, 0, width, height); // Set the viewport to be the entire window
	//gluPerspective(45, ratio, 1, 100); // Set the correct perspective
	gluPerspective(45, ratio, 0, 100); // Set the correct perspective
	glMatrixMode(GL_MODELVIEW); // Get Back to the Modelview
}

glApp::glApp(const char* label) {
	angleView = 0.0;
	currentInstance = this;
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow(label);

}

void glApp::run() {
	//std::thread t1(threadOne);
	//std::thread t2(threadTwo);
	
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboardCallback);
	glutMouseFunc(mouseButtonCallback);
	glutMotionFunc(mouseMoveCallback);
	glutIdleFunc(idleCallback);
	glutMainLoop();
	//t1.join();
	//t2.join();
	
	
}

void glApp::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	g.draw();
	glFlush();
	glutSwapBuffers();
}

void glApp::idle() {
	glutPostRedisplay();
}

void glApp::mouseMove(int x, int y) {
	if (isDragging) { // only when dragging
					  // update the change in angle
		deltaAngle = (x - xDragStart) * 0.005;
		std::cout << "Delta Angle: " << deltaAngle << std::endl;
		glTranslatef(0, 0, -5.0);
		glRotatef(deltaAngle, 0.0, 0.0, -2.0);
		glTranslatef(0, 0, 5.0);
	}
}

void glApp::mouseButton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) { // left mouse button pressed
			isDragging = 1; // start dragging
			xDragStart = x; // save x where button first pressed
		}
		else { /* (state = GLUT_UP) */
			angle += deltaAngle; // update camera turning angle
			isDragging = 0; // no longer dragging
		}
	}
}

void glApp::rotateLeft() {
	glTranslatef(0, 0, -5.0);
	glRotatef(1.0f, 0.0, 0.0, -2.0);
	glTranslatef(0, 0, 5.0);
}

void glApp::rotateRight() {
	glTranslatef(0, 0, -5.0);
	glRotatef(1.0f, 0.0f, 0.0f, 2.0f);
	glTranslatef(0, 0, 5.0);
}

void glApp::rotateUp() {
	glTranslatef(0, 0, -5.0);
	glRotatef(1.0f, -2.0f, 0.0f, 0.0f);
	glTranslatef(0, 0, 5.0);
}

void glApp::rotateDown() {
	glTranslatef(0, 0, -5.0);
	glRotatef(1.0f, 2.0f, 0.0f, 0.0f);
	glTranslatef(0, 0, 5.0);
}

void delay() {

}

void glApp::animate() {
	for (int i = 0; i < 100; i++) {
		g.runAlgorithmIteration();
		//glutDisplayFunc(displayCallback);
		render();
		//sleep(500);

	}
}

void glApp::keypress(unsigned char key) {
	if (key == 114) {
		g.runAlgorithmIteration();
	}
	if (key == 't') {
		//g.runAlgorithm();
		//t
		animate();

	}
	if (key == 97) {
		rotateLeft();
	}
	if (key == 100) {
		rotateRight();
	}
	if (key == 119) {
		rotateUp();
	}
	if (key == 115) {
		rotateDown();
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

