#include <freeglut.h>
#include <iostream>
#include <algorithm>
#include "centroid.h"

centroid::centroid() {}
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

centroid::centroid(float xx, float yy, float zz) {
	x = xx;
	y = yy;
	z = zz;
	r = 0;
	g = 0;
	b = 0;
	size = 10.0;
}
centroid::centroid(float xx, float yy, float zz, float ss, int gs) {
	x = xx;
	y = yy;
	z = zz;
	r = 0;
	g = 0;
	b = 0;
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

void centroid::draw() {
	// Draw a triangle:
	glBegin(GL_TRIANGLES);
	glColor3f(r, g, b);
	// Lower left vertex
	glVertex3f(x - 0.05, y - 0.05, -5.0f);
	// Lower right vertex
	glVertex3f(x + 0.05, y - 0.05, -5.0f);
	// Upper vertex
	glVertex3f(x, y + 0.025, -5.0f);
	glEnd();

}

void centroid::addMember(point & a) {
	members.push_back(a);
}

int centroid::membersSize() {
	return members.size();
}

float centroid::computeXAverage() {
	if (members.size() == 0) { return x; }
	//std::cout << "Computing X averages" << std::endl;
	float xx = 0, temp = 0;
	float count = 0;
	for (std::vector<point>::iterator i = members.begin(); i != members.end(); ++i) {
		temp = i->getX();
		//std::cout << temp << std::endl;
		xx += temp;
		count++;
	}
	return (xx / count);
}

float centroid::computeYAverage() {
	if (members.size() == 0) { return y; }
	float yy = 0;
	float count = 0;
	for (int i = 0; i < members.size(); i++) {
		yy += members[i].getY();
		count++;
	}
	return (yy / count);
}

void centroid::drawConnections() {
	float xx, yy, zz;
	glLineWidth(0.25);
	glColor3f(0, 0, 1);
	for (int i = 0; i < members.size(); i++) {
		glBegin(GL_LINES);
		glVertex3f(x, y, z);
		//std::cout << members[i].getX() << members[i].getY() << members[i].getZ() << std::endl;
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
	//std::vector<point>::iterator it;
	//it = find(members.begin(), members.end(), a);
	//members.erase(it);
	for (int i = 0; i < members.size(); i++) {
		if (members[i].getTag() == a.getTag()) {
			members.erase(members.begin() + i);
			//break;
		}
	}


}