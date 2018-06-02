#include "graph.h"

#ifndef glApp_hpp
#define glApp_hpp

class glApp {
	graph g;
	int width, height;
	
public:
	glApp::glApp(const char* label);
	void run();
	void render();
	void keypress(unsigned char);
	void mouse();
	void windowToScene(float &, float &);
};
#endif