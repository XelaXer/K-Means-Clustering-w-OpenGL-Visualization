#include <freeglut.h>
#include "point.h"

point::point() {}

point::point(float xx, float yy, float zz) {
	x = xx;
	y = yy;
	z = zz;
	r = 0;
	g = 0;
	b = 0;
	size = 10.0;
}
point::point(float xx, float yy, float zz, float sizeS) {
	x = xx;
	y = yy;
	z = zz;
	r = 0;
	g = 0;
	b = 0;
	size = sizeS;
}

point::point(float xx, float yy, float zz, float rr, float gg, float bb, float sizeS) {
	x = xx;
	y = yy;
	z = zz;
	r = rr;
	g = gg;
	b = bb;
	size = sizeS;
}

float point::getX() { return x; }
float point::getY() { return y; }
float point::getZ() { return z; }
float point::getR() { return r; }
float point::getG() { return g; }
float point::getB() { return b; }
float point::getSize() { return size; }
int point::getGroup() { return group; }
std::string point::getLabel() { return label; }
void point::setX(float k) { x = k; }
void point::setY(float k) { y = k; }
void point::setZ(float k) { z = k; }
void point::setR(float k) { r = k; }
void point::setG(float k) { g = k; }
void point::setB(float k) { b = k; }
void point::setSize(float k) { size = k; }
void point::setGroup(int k) { group = k; }
void point::setLabel(std::string k) { label = k; }

void point::draw() {
	glPointSize(size);
	glBegin(GL_POINTS);
	glColor3f(r, g, b);
	glVertex3f(x, y, z);
	glEnd();
}