#include <cmath>
#include <freeglut.h>
#include <iostream>
#include <thread>
#include "kmeansclustering.h"
#include "point.h"
#include "glApp.h"

void kmeans::setK(unsigned int kk) { k = kk; }
unsigned int kmeans::getK() { return k; }

inline float kmeans::euclideanDistance2D(point &a, centroid &b) {
	return (sqrt(powf((b.getX() - a.getX()), 2.0f) + powf((b.getY() - a.getY()), 2.0f)+ powf((b.getZ() - a.getZ()), 2.0f)));
}

inline int kmeans::findNearestCentroid(point &a, std::vector<centroid> & centroids) {
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

void kmeans::checkPoint(point &p, std::vector<centroid> & centroids, int index) {
	if (!centroids[index].contains(p)) {	// Check for duplicate point
		centroids[index].addMember(p);
		for (int j = 0; j < centroids.size(); j++) { // Swap point from old centroid to new centroid
			if ((j != index) && (centroids[j].contains(p))) {
				centroids[j].removeMember(p);
			}
		}
	}
}

void kmeans::run(std::vector<point> & points, std::vector<centroid> & centroids, unsigned int k) {
	int index;
	int maxIterations = 10;
	for (int itr = 0; itr < maxIterations; itr++) {
		for (std::vector<point>::iterator i = points.begin(); i != points.end(); ++i) {
			index = findNearestCentroid(*i, centroids);
			i->setGroup(centroids[index].getGroup());
			checkPoint(*i, centroids, index);
		}
		for (std::vector<centroid>::iterator i = centroids.begin(); i != centroids.end(); ++i) {
			i->computeAverage();
		}
	}
}

void kmeans::runIteration(std::vector<point> & points, std::vector<centroid> & centroids, unsigned int k) {
	int index;
	for (std::vector<point>::iterator i = points.begin(); i != points.end(); ++i) {
		index = findNearestCentroid(*i, centroids);
		i->setGroup(centroids[index].getGroup());
		checkPoint(*i, centroids, index);
	}
	for (std::vector<centroid>::iterator i = centroids.begin(); i != centroids.end(); ++i) {
		i->computeAverage();
	}
}

void kmeans::computeT1(std::vector<point> & points, std::vector<centroid> & centroids) {
	std::cout << "Running Thread 1" << std::endl;
	int index = 0;
	for (int i = 0; i < points.size()/2; i++) {
		index = findNearestCentroid(points[i], centroids);
		points[i].setGroup(centroids[index].getGroup());
		checkPoint(points[i], centroids, index);
	}
}

void kmeans::computeT2(std::vector<point> & points, std::vector<centroid> & centroids) {
	std::cout << "Running Thread 2" << std::endl;
	int index = 0;
	for (int i = (points.size() / 2); i < points.size(); i++) {
		
		index = findNearestCentroid(points[i], centroids);
		std::cout << "Index: " << index << std::endl;
		points[i].setGroup(centroids[index].getGroup());
		std::cout << "Group: " << points[i].getGroup() << std::endl;
		checkPoint(points[i], centroids, index);
	}
}



void kmeans::runMultiThread(std::vector<point> & points, std::vector<centroid> & centroids) {

	std::cout << "Created Thread 1" << std::endl;
	std::thread t1(&kmeans::computeT1, this, (points), (centroids));
	std::cout << "Created Thread 2" << std::endl;
	std::thread t2(&kmeans::computeT2, this, (points), (centroids));

	t1.join();
	t2.join();
	std::cout << "Threads Joined" << std::endl;
	//computeT1(points, centroids);
	//computeT2(points, centroids);

	for (std::vector<centroid>::iterator i = centroids.begin(); i != centroids.end(); ++i) {
		i->computeAverage();
	}

}




//
//void kmeans::computeT2(std::vector<point> & points, std::vector<centroid> & centroids, int index) {
//	for (std::vector<point>::iterator i = points.begin() + (points.size()/2); i != points.end(); ++i) {
//		index = findNearestCentroid(*i, centroids);
//		i->setGroup(centroids[index].getGroup());
//		checkPoint(*i, centroids, index);
//	}
//}
//std::thread t1(&kmeans::computeT1, this, std::ref(points), std::ref(centroids), std::ref(index));
//	std::thread t2(&kmeans::computeT2, this, std::ref(points), std::ref(centroids), std::ref(index));
//t1.join();
//t2.join();
