#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "graph.h"
#include "point.h"
#include "grid.h"

graph::graph() {
	iterationCount = 0;
	initialize();
}

void graph::initialize() {
	std::ifstream myfile("input.txt");
	std::string line;
	std::string temp;
	std::stringstream ss;
	float x, y, z, s;
	int k, tag = 0, count = 0;
	char c;
	std::cout << "Enter the number of clusters:";
	std::cin >> k;
	km.setK(k);
	std::cout << std::endl;
	std::cout << "Random Data (y) or Data from Text File (n): ";
	std::cin >> c;
	std::cout << std::endl;
	if (c == 'y') {
		points.reserve(100);
		generateRandomData(100);
	} else if (c == 'n') {
		if (myfile.is_open()) {
			while (std::getline(myfile, line)) {
				std::cout << line << '\n';
				std::stringstream ss(line);
				ss >> x >> y >> z >> s;
				std::cout << x << " " << y << " " << z << " " << s << std::endl;
				points.push_back((point(x, y, z, s, tag++)));
			}
			myfile.close();
		} else {
			std::cout << "Unable to open file" << std::endl;
		}
	}
	generateCentroids();
}

void graph::generateCentroids() {
	srand(static_cast <unsigned> (time(0)));
	float x, y, z, s;
	int group = 0;
	for (int i = 0; i < km.getK(); i++) {
		x = -2.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2.0 - (-2.0))));
		y = -2.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2.0 - (-2.0))));
		centroids.push_back(centroid(x, y, -5.0, 8.0, group++));
	}
}

void graph::generateRandomData(int amount) {
	int tag = 0;
	srand(static_cast <unsigned> (time(0)));
	float x, y, z, s;
	for (int i = 0; i < amount; i++) {
		x = -2.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2.0 - (-2.0))));
		y = -2.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2.0 - (-2.0))));
		points.push_back(point(x, y, -5.0, 5.0, tag++));
	}
}

void graph::draw() {
	g.draw();
	for (int i = 0; i < points.size(); i++) {
		points[i].draw();
	}
	for (int i = 0; i < centroids.size(); i++) {
		centroids[i].draw();
		centroids[i].drawConnections();
	}
}

void graph::runAlgorithm() {
	std::cout << "K-Means Clustering Algorithm Started" << std::endl;
	km.run(points, centroids, km.getK());
}

void graph::runAlgorithmIteration() {
	std::cout << "K-Means Clustering Iteration: " << iterationCount << std::endl;
	km.runIteration(points, centroids, km.getK());
}