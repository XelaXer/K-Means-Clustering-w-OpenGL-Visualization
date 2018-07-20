#include <freeglut.h>
#include <iostream>
#include <algorithm>
#include "centroid.h"

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
int centroid::membersSize() { return members.size(); }

centroid::centroid() {
	x = 0;
	y = 0;
	z = 0;
	r = 0;
	g = 0;
	b = 0;
	xAvg = 0;
	yAvg = 0;
	zAvg = 0;
	size = 10.0;
}

centroid::centroid(float xx, float yy, float zz) {
	x = xx;
	y = yy;
	z = zz;
	r = 0;
	g = 0;
	b = 0;
	xAvg = 0;
	yAvg = 0;
	zAvg = 0;
	size = 10.0;
}

centroid::centroid(float xx, float yy, float zz, float ss, int gs) {
	x = xx;
	y = yy;
	z = zz;
	r = 0;
	g = 0;
	b = 0;
	xAvg = 0;
	yAvg = 0;
	zAvg = 0;
	size = ss;
	group = gs;
}

centroid::centroid(float xx, float yy, float zz, float sizeS) {
	x = xx;
	y = yy;
	z = zz;
	r = 0;
	g = 0;
	b = 0;
	xAvg = 0;
	yAvg = 0;
	zAvg = 0;
	size = sizeS;
}

centroid::centroid(float xx, float yy, float zz, float rr, float gg, float bb, float sizeS, int gs) {
	x = xx;
	y = yy;
	z = zz;
	r = rr;
	g = gg;
	b = bb;
	xAvg = 0;
	yAvg = 0;
	zAvg = 0;
	size = sizeS;
	group = gs;
}

void centroid::draw() {
	// Draw a triangle:
	glBegin(GL_TRIANGLES);
	glColor3f(r, g, b);
	// Lower left vertex
	//glVertex3f(x - 0.05, y - 0.05, z-5.0f);
	// Lower right vertex
	//glVertex3f(x + 0.05, y - 0.05, z-5.0f);
	// Upper vertex
	//glVertex3f(x, y + 0.025, z-5.0f);
	glEnd();
}

void centroid::addMember(point & a) {
	a.setR(r);
	a.setB(b);
	a.setG(g);
	members.push_back(a);
}



void centroid::computeAverage() {
	if (members.size() == 0) { return; }
	float xx = 0, yy = 0, zz = 0;
	float count = 0;
	for (std::vector<point>::iterator i = members.begin(); i != members.end(); ++i) {
		xx += i->getX();
		yy += i->getY();
		zz += i->getZ();
		count++;
	}
	x = (xx / count);
	y = (yy / count);
	z = (zz / count);
}

float centroid::computeXAverage() {
	if (members.size() == 0) { return x; }
	float xx = 0, temp = 0;
	float count = 0;
	for (std::vector<point>::iterator i = members.begin(); i != members.end(); ++i) {
		xx += i->getX();
		count++;
	}
	return (xx / count);
}

float centroid::computeYAverage() {
	if (members.size() == 0) { return y; }
	float yy = 0, temp = 0;
	float count = 0;
	for (std::vector<point>::iterator i = members.begin(); i != members.end(); ++i) {
		yy += i->getY();
		count++;
	}
	return (yy / count);
}

float centroid::computeZAverage() {
	if (members.size() == 0) { return z; }
	float zz = 0, temp = 0;
	float count = 0;
	for (std::vector<point>::iterator i = members.begin(); i != members.end(); ++i) {
		zz += i->getZ();
		count++;
	}
	return (zz / count);
}

void centroid::drawConnections() {
	float xx, yy, zz;
	glLineWidth(0.08);
	glColor3f(r, g, b);
	for (int i = 0; i < members.size(); i++) {
		glBegin(GL_LINES);
		glVertex3f(x, y, z);
		xx = members[i].getX();
		yy = members[i].getY();
		zz = members[i].getZ();
		glVertex3f(xx, yy, zz);
		glEnd();
	}
}

bool centroid::contains(point & a) {
	for (int i = 0; i < members.size(); i++) {
		if (a.getTag() == members[i].getTag()) {
			return true;
		}
	}
	return false;
}

void centroid::removeMember(point & a) {
	for (int i = 0; i < members.size(); i++) {
		if (members[i].getTag() == a.getTag()) {
			members.erase(members.begin() + i);
		}
	}
}