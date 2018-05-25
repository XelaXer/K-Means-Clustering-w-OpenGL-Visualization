#include <cmath>
#include "kmeansclustering.h"
#include "point.h"

float euclideanDistance2D(point &a, centroid &b) {
	return (sqrt(pow((b.getX() - a.getX()), 2.0) + pow((b.getY() - a.getY()), 2.0)));
}

int findNearestCentroid(point &a, std::vector<centroid> & centroids) {
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

