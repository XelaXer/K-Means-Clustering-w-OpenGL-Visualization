#include <freeglut.h>
#include "centroid.h"

centroid::centroid() {}

centroid::centroid(float xx, float yy, float zz) {
	x = xx;
	y = yy;
	z = zz;
	r = 0;
	g = 0;
	b = 0;
	size = 10.0;
}
centroid::centroid(float xx, float yy, float zz, float sizeS) {
	x = xx;
	y = yy;
	z = zz;
	r = 0;
	g = 0;
	b = 0;
	size = sizeS;
}

centroid::centroid(float xx, float yy, float zz, float rr, float gg, float bb, float sizeS) {
	x = xx;
	y = yy;
	z = zz;
	r = rr;
	g = gg;
	b = bb;
	size = sizeS;
}

float centroid::getX() { return x; }
float centroid::getY() { return y; }
float centroid::getZ() { return z; }
float centroid::getR() { return r; }
float centroid::getG() { return g; }
float centroid::getB() { return b; }
float centroid::getSize() { return size; }
int centroid::getGroup() { return group; }
std::string centroid::getLabel() { return label; }
void centroid::setX(float k) { x = k; }
void centroid::setY(float k) { y = k; }
void centroid::setZ(float k) { z = k; }
void centroid::setR(float k) { r = k; }
void centroid::setG(float k) { g = k; }
void centroid::setB(float k) { b = k; }
void centroid::setSize(float k) { size = k; }
void centroid::setGroup(int k) { group = k; }
void centroid::setLabel(std::string k) { label = k; }

void centroid::draw() {
	// Replace with small triangle
	glPointSize(size);
	glBegin(GL_POINTS);
	glColor3f(r, g, b);
	glVertex3f(x, y, z);
	glEnd();
}