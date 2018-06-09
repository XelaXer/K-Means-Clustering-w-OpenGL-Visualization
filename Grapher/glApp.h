#include "graph.h"

#ifndef glApp_hpp
#define glApp_hpp

class glApp {
	graph g;
	int width, height;
	float angleView;
	
	
public:
	bool mouseDown;
	glApp::glApp(const char* label);
	void run();
	void rotateLeft();
	void rotateRight();
	void rotateUp();
	void rotateDown();
	void render();
	void keypress(unsigned char);
	void mouse();
	void windowToScene(float &, float &);
};
#endif