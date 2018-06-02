#ifndef grid_hpp
#define grid_hpp

class grid {
	int width, height;

public:
	grid::grid();
	void initialize(); // For setting up notches and grid dimensions
	void draw();
	void drawGrid();
	void drawNotches();
	int getWidth();
	int getHeight();
};


#endif
