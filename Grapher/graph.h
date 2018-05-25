#include <vector>
#include "grid.h"
#include "point.h"
#include "centroid.h"

#ifndef graph_hpp
#define graph_hpp

class graph {
	grid g;
	std::vector<point> points;
	std::vector<centroid> centroids;

public:
	graph::graph();
	void draw();
	void initialize();
};
#endif