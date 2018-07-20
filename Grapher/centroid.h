#include <string>
#include <vector>
#include "point.h"

#ifndef centroid_hpp
#define centroid_hpp

class centroid {
	float x, y, z;
	float r, g, b;
	float xAvg, yAvg, zAvg;
	float size;
	int group;
	std::string label;
	std::vector<point> members;
public:
	centroid::centroid();
	centroid::centroid(float, float, float);
	centroid::centroid(float, float, float, float);
	centroid::centroid(float, float, float, float, int);
	centroid::centroid(float, float, float, float, float, float, float, int);
	float getX();
	float getY();
	float getZ();
	float getR();
	float getG();
	float getB();
	float getSize();
	int getGroup();
	std::string getLabel();
	void setX(float);
	void setY(float);
	void setZ(float);
	void setR(float);
	void setG(float);
	void setB(float);
	void setSize(float);
	void setGroup(int);
	void setLabel(std::string);
	void draw();
	void addMember(point &);
	int membersSize();
	float computeXAverage();
	float computeYAverage();
	float computeZAverage();
	void drawConnections();
	bool contains(point &);
	void removeMember(point &);
	void computeAverage();
};

#endif