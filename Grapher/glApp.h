#include "graph.h"

#ifndef glApp_hpp
#define glApp_hpp

class glApp {
	graph g;
	
public:
	glApp::glApp(const char* label);
	void run();
	void render();
};
#endif