#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "graph.h"
#include "point.h"
#include "grid.h"

graph::graph() {
	initialize();
}

void graph::initialize() {
	std::ifstream myfile("input.txt");
	std::string line;
	std::string temp;
	std::stringstream ss;
	float x, y, z, s;
	if (myfile.is_open()) {
		while (std::getline(myfile, line)) {
			std::cout << line << '\n';
			std::stringstream ss(line);
			ss >> x >> y >> z >> s;
			std::cout << x << " " << y << " " << z << " " << s << std::endl;
			points.push_back((point(x, y, z, s)));
		}
		myfile.close();
	} else {
		std::cout << "Unable to open file" << std::endl;
	}
}

void graph::draw() {
	g.draw();
	for (int i = 0; i < points.size(); i++) {
		points[i].draw();
	}
}