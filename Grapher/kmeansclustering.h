#include <vector>
#include "point.h"
#include "centroid.h"
#include "cluster.h"

#ifndef kmeansclustering_hpp
#define kmeansclustering_hpp

class kmeans {
	unsigned int k;
	// add constructor that takes the "k" for the number of clusters
	
public:
	inline float euclideanDistance2D(point &, centroid &);
	inline int findNearestCentroid(point &, std::vector<centroid> &);
	void run(std::vector<point> &, std::vector<centroid> &, unsigned int);
	void runIteration(std::vector<point> &, std::vector<centroid> &, unsigned int);
	void setK(unsigned int);
	unsigned int getK();
	void checkPoint(point &p, std::vector<centroid> & centroids, int index);
	void computeT1(std::vector<point> &, std::vector<centroid> &);
	void computeT2(std::vector<point> &, std::vector<centroid> &);
	//void runMultiThread(std::vector<point> &, std::vector<centroid> &);
};

#endif