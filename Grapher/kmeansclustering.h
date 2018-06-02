#include <vector>
#include "point.h"
#include "centroid.h"
#include "cluster.h"

#ifndef kmeansclustering_hpp
#define kmeansclustering_hpp

class kmeans {
	std::vector<cluster> clusters;
	unsigned int k;
	// add constructor that takes the "k" for the number of clusters
public:
	float euclideanDistance2D(point &, centroid &);
	int findNearestCentroid(point &, std::vector<centroid> &);
	void run(std::vector<point> &, std::vector<centroid> &, unsigned int);
	void runIteration(std::vector<point> &, std::vector<centroid> &, unsigned int);
	void setK(unsigned int);
	unsigned int getK();
};

#endif