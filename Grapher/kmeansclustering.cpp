#include <cmath>
#include <iostream>
#include "kmeansclustering.h"
#include "point.h"
#include "glApp.h"

void kmeans::setK(unsigned int kk) { k = kk; }
unsigned int kmeans::getK() { return k; }

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

void kmeans::run(std::vector<point> & points, std::vector<centroid> & centroids, unsigned int k) {
	int index;
	int maxIterations = 15;
	float x, y;
	for (int itr = 0; itr < maxIterations; itr++) {
		for (std::vector<point>::iterator i = points.begin(); i != points.end(); ++i) {
			index = findNearestCentroid(*i, centroids);
			i->setGroup(centroids[index].getGroup());
			if (!centroids[index].contains(*i)) {	// Check for duplicate point
				centroids[index].addMember(*i);
				for (int j = 0; j < centroids.size(); j++) { // Swap point from old centroid to new centroid
					if ((j != index) && (centroids[j].contains(*i))) {
						centroids[j].removeMember(*i);
					}
				}
			}
			// Console Checks
			std::cout << "Point " << i->getX() << ", " << i->getY();
			std::cout << " assigned to centroid " << centroids[index].getGroup();
			std::cout << std::endl;
		}
		for (std::vector<centroid>::iterator i = centroids.begin(); i != centroids.end(); ++i) {
			x = i->computeXAverage();
			y = i->computeYAverage();
			i->setX(x);
			i->setY(y);
			i->draw();
			std::cout << "Centroid " << i->getGroup() << " new x = " << x;
			std::cout << std::endl;
			std::cout << "Centroid " << i->getGroup() << " new y = " << y;
			std::cout << std::endl;
		}
	}
}

void kmeans::runIteration(std::vector<point> & points, std::vector<centroid> & centroids, unsigned int k) {
	int index;
	float x, y;
	for (std::vector<point>::iterator i = points.begin(); i != points.end(); ++i) {
		index = findNearestCentroid(*i, centroids);
		i->setGroup(centroids[index].getGroup());
		if (!centroids[index].contains(*i)) {	// Check for duplicate point
			centroids[index].addMember(*i);
			for (int j = 0; j < centroids.size(); j++) { // Swap point from old centroid to new centroid
				if ((j != index) && (centroids[j].contains(*i))) {
					centroids[j].removeMember(*i);
				}
			}
		}
		// Console Checks
		std::cout << "Point " << i->getX() << ", " << i->getY();
		std::cout << " assigned to centroid " << centroids[index].getGroup();
		std::cout << std::endl;
	}
	for (std::vector<centroid>::iterator i = centroids.begin(); i != centroids.end(); ++i) {
		x = i->computeXAverage();
		y = i->computeYAverage();
		i->setX(x);
		i->setY(y);
		i->draw();
		std::cout << "Centroid " << i->getGroup() << " new x = " << x;
		std::cout << std::endl;
		std::cout << "Centroid " << i->getGroup() << " new y = " << y;
		std::cout << std::endl;
	}
}