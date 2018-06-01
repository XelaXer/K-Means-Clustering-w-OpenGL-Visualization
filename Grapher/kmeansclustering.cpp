#include <cmath>
#include "kmeansclustering.h"
#include "point.h"

float kmeans::euclideanDistance2D(point &a, centroid &b) {
	return (sqrt(pow((b.getX() - a.getX()), 2.0) + pow((b.getY() - a.getY()), 2.0)));
}

int kmeans::findNearestCentroid(point &a, std::vector<centroid> & centroids) {
	int centroidT = 0;
	float distance;
	float nearest = euclideanDistance2D(a, centroids[0]);
	for (int i = 1; i < centroids.size(); i++) {
		distance = euclideanDistance2D(a, centroids[i]);
		if (nearest > distance) {
			nearest = distance;
			centroidT = i;
		}
	}
	return centroidT;
}

// Place centroids randomly
// Repeat until convergence
// For each point
// Find nearest centroid j (use minimum Euclidean Distance)
// ^ check all centroids
// Assign the point to cluster (centroid) j

void kmeans::run(std::vector<point> & points, std::vector<centroid> & centroids, unsigned int k) {
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