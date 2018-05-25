#include "grid.h"
#include <freeglut.h>

grid::grid() {}

void grid::draw() {
	drawGrid();
	drawNotches();
}

void grid::drawGrid() {
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClearColor(1.0, 1.0, 1.0, 0.0);

	// For Grid
	glLineWidth(2.5);
	glColor3f(0.75, 0.75, 0.75);

	// Vertical Axis
	glBegin(GL_LINES);
	glVertex3f(0, 2, -5.0);
	glVertex3f(0, -2, -5.0);
	glEnd();

	// Horizontal Axis
	glBegin(GL_LINES);
	glVertex3f(2, 0, -5.0);
	glVertex3f(-2, 0, -5.0);
	glEnd();
}

void grid::drawNotches() {
	// Notches
	glLineWidth(1);
	// Y-Axis
	// Positive
	for (double i = 0.05; i < 2; i += 0.1) {
		glBegin(GL_LINES);
		glVertex3f(0.05, i, -5.0);
		glVertex3f(-0.05, i, -5.0);
		glEnd();
	}
	// Negative
	for (double i = 0.05; i < 2; i += 0.1) {
		glBegin(GL_LINES);
		glVertex3f(0.05, -i, -5.0);
		glVertex3f(-0.05, -i, -5.0);
		glEnd();
	}

	// X-Axis
	// Positive
	for (float i = 0.05; i < 2; i += 0.1) {
		glBegin(GL_LINES);
		glVertex3f(i, 0.05, -5.0);
		glVertex3f(i, -0.05, -5.0);
		glEnd();
	}
	// Negative
	for (float i = 0.05; i < 2; i += 0.1) {
		glBegin(GL_LINES);
		glVertex3f(-i, 0.05, -5.0);
		glVertex3f(-i, -0.05, -5.0);
		glEnd();
	}
}

void grid::initialize() {

}

int grid::getHeight() {
	return height;
}

int grid::getWidth() {
	return width;
}