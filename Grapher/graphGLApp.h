/*
#ifndef graphglapp_hpp
#define graphglapp_hpp

#include "glApp.h"
#include "graph.h"

class graphGLApp : public glApp {
	graph g;
public:
	graphGLApp::graphGLApp();
	graphGLApp::graphGLApp(const char* label);
	void render();
	void run();
	void draw();
};

void graphGLApp::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	g.draw();
	glFlush();
	glutSwapBuffers();
}
#endif
*/