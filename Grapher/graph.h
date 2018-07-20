#include <vector>
#include <thread>
#include "grid.h"
#include "point.h"
#include "centroid.h"
#include "kmeansclustering.h"

#ifndef graph_hpp
#define graph_hpp

class graph {
	grid g;
	kmeans km;
	std::vector<point> points;
	std::vector<centroid> centroids;
	float angleView;


public:
	int iterationCount;
	int maxItrCount;
	graph::graph();
	void rotate();
	void draw();
	void initialize();
	void generateRandomData(int);
	void runAlgorithm();
	void runAlgorithmIteration();
	void generateCentroids();
	void autorun();
	void rotateLeft();
	void rotateRight();
	void rotateUp();
	void rotateDown();
	void reset();
	void runMultiThread();
	void experimentalDraw();

};
#endif