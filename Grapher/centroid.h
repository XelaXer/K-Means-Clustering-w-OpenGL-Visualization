#include <string>
#include "point.h"

#ifndef centroid_hpp
#define centroid_hpp

class centroid : point {
	float x, y, z;
	float r, g, b;
	float size;
	int group;
	std::string label;
public:
	centroid::centroid();
	centroid::centroid(float, float, float);
	centroid::centroid(float, float, float, float);
	centroid::centroid(float, float, float, float, float, float, float);
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
};

#endif