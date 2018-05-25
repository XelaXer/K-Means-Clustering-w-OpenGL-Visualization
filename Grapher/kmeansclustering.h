#include <vector>
#include "point.h"
#include "centroid.h"
#include "cluster.h"

#ifndef kmeansclustering_hpp
#define kmeansclustering_hpp



// Place centroids randomly
// Repeat until convergence
	// For each point
		// Find nearest centroid j (use minimum Euclidean Distance)
		// ^ check all centroids
		// Assign the point to cluster (centroid) j


float euclideanDistance2D(point &a, centroid &b);
int findNearestCentroid(point &a, std::vector<centroid> & centroids);




void run(std::vector<point> & points, std::vector<centroid> & centroids, int k) {
	// Need input for how many clusters, "k"
	// This assigns each point to its closest centroid
	int index;
	for (int i = 0; i < points.size(); i++) {
		index = findNearestCentroid(points[i], centroids);
		points[i].setGroup(centroids[index].getGroup());
		// Assign point to a cluster
	}
	// For each cluster
}

#endif