#include <vector>
#include "point.h"
#include "centroid.h"

#ifndef cluster_hpp
#define cluster_hpp

class cluster {
	int id;
	centroid c;
	std::vector<point> members;
public:
	void setID(int);
	int getID();
	void addMember(point);
	point getMember(int);
	void setCentroid(centroid);
	centroid getCentroid();

};

#endif