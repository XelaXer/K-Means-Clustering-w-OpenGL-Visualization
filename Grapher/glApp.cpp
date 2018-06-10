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
	currentInstance->keypress(key, x, y);
}

void keyboardUpCallback(unsigned char const key, int x, int y) {
	currentInstance->keypressUp(key, x, y);
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

void glApp::rotateLeft() {
}

void glApp::rotateRight() {
}

void glApp::rotateUp() {
}

void glApp::rotateDown() {
}


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

void th1() {
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(resize);
}

void th2() {
	glutKeyboardFunc(keyboardCallback);
	glutKeyboardUpFunc(keyboardUpCallback);
	glutMouseFunc(mouseButtonCallback);
	glutMotionFunc(mouseMoveCallback);
}

void glApp::run() {
	std::thread t1(th1);
	std::thread t2(th2);
	
	
	//glutDisplayFunc(displayCallback);
	//glutReshapeFunc(resize);
	//glutKeyboardFunc(keyboardCallback);
	//glutMouseFunc(mouseButtonCallback);
	//glutMotionFunc(mouseMoveCallback);
	//glutIdleFunc(idleCallback);
	//glutMainLoop();
	//t1.join();
	//t2.join();
	glutIdleFunc(idleCallback);
	glutMainLoop();
	
	
}

void glApp::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	g.draw();
	glFlush();
	glutSwapBuffers();
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
	if ((button == 3) || (button == 4)) {
		if (state == GLUT_UP){
			gluLookAt(0, 0, 0, 0, 0, -5, 0, 1, 0);
		}
	}
}

void glApp::animate() {
	for (int i = 0; i < 100; i++) {
		g.runAlgorithmIteration();
		render();
	}
}

void glApp::idle() {
	checkKeyboard();
	glutPostRedisplay();
}

void glApp::checkKeyboard() {
	if (buffer[114] == true) {
		g.runAlgorithmIteration();
	}
	if (buffer[116] == true) {
		animate();
	}
	if (buffer[97] == true) {
		g.rotateLeft();
	}
	if (buffer[100] == true) {
		g.rotateRight();
	}
	if (buffer[119] == true) {
		g.rotateUp();
	}
	if (buffer[115] == true) {
		g.rotateDown();
	}
	/*if (key == 'i') {
		gluLookAt(0, -5, -5, 0, 0, -5, 0, 1, 0);
		std::cout << "Pressed i" << std::endl;;
	}*/
}

void glApp::keypressUp(int key, int x, int y) {
	buffer[key] = false;
}

void glApp::keypress(unsigned char key,int x, int y) {
	buffer[key] = true;
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

