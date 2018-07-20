#include "graph.h"

#ifndef glApp_hpp
#define glApp_hpp

class glApp {
	graph g;
	int width, height;
	float angleView;
	clock_t time;
	
	
public:
	bool buffer[128];
	//std::thread t1;
	//bool mouseDown;
	// Camera position
	float x = 0.0, y = -5.0; // initially 5 units south of origin
	float deltaMove = 0.0; // initially camera doesn't move

	// Camera direction
	float lx = 0.0, ly = 1.0; // camera points initially along y-axis
	float angle = 0.0; // angle of rotation for the camera direction
	float deltaAngle = 0.0; // additional angle change when dragging

	// Mouse drag control
	bool isDragging = 0; // true when dragging
	int xDragStart = 0; // records the x-coordinate when dragging starts

	glApp::glApp(const char* label);
	void run();
	void idle();
	void rotateLeft();
	void rotateRight();
	void rotateUp();
	void rotateDown();
	void render();
	void keypress(unsigned char,int, int);
	void keypressUp(int, int, int);
	void mouseMove(int,int);
	void mouseButton(int, int, int, int);
	void windowToScene(float &, float &);
	void animate();
	void checkKeyboard();
	void test();
	std::thread runThreadedAlgoItr();
};
#endif