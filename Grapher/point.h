#include <string>

#ifndef point_hpp
#define point_hpp

class point {
	float x, y, z;
	float r, g, b;
	float size;
	int group;
	int tag; // unique numerical identifier used to check for repeats
	std::string label;
public:
	point::point();
	point::point(float, float, float);
	point::point(float, float, float, float, int);
	point::point(float, float, float, float, float, float, float);
	float getX();
	float getY();
	float getZ();
	float getR();
	float getG();
	float getB();
	float getSize();
	int getGroup();
	int getTag();
	std::string getLabel();
	void setX(float);
	void setY(float);
	void setZ(float);
	void setR(float);
	void setG(float);
	void setB(float);
	void setSize(float);
	void setGroup(int);
	void setTag(int);
	void setLabel(std::string);
	void draw();
};
#endif