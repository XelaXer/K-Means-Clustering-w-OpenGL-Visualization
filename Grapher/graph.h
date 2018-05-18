/* Add all elements of the graph to this object */
#include "grid.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

#ifndef graph_hpp
#define graph_hpp
class graph {
	grid g;
	std::vector<point> points;

public:
	graph::graph() {
		initialize();
	}
	void draw();
	void initialize();
};

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
	}  else {
		std::cout << "Unable to open file" << std::endl;
	}
}

void graph::draw() {
	g.draw();
	for (int i = 0; i < points.size(); i++) {
		points[i].draw();
	}
}
#endif