#ifndef point_hpp
#define point_hpp

#include <freeglut.h>

class point {
	float x, y, z;
	float r, g, b;
	float size;
	// string label;
public:
	point::point() {
	}
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
	
	float getX();
	float getY();
	float getZ();
	float getR();
	float getG();
	float getB();
	float getSize();
	void setX(float k);
	void setY(float k);
	void setZ(float k);
	void setR(float k);
	void setG(float k);
	void setB(float k);
	void setSize(float k);
	void draw();
};

float point::getX() { return x; }
float point::getY() { return y; }
float point::getZ() { return z; }
float point::getR() { return r; }
float point::getG() { return g; }
float point::getB() { return b; }
float point::getSize() { return size; }
void point::setX(float k) { x = k; }
void point::setY(float k) { y = k; }
void point::setZ(float k) { z = k; }
void point::setR(float k) { r = k; }
void point::setG(float k) { g = k; }
void point::setB(float k) { b = k; }
void point::setSize(float k) { size = k; }
void point::draw() {
	glPointSize(size);
	glBegin(GL_POINTS);
	glColor3f(r, g, b);
	glVertex3f(x, y, z);
	glEnd();
}
#endif