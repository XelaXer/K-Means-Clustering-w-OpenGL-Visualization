#include "glApp.h"

int main(int argc, char** argv) {
	const char* label = "Grapher";
	// GLUT Initialization
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	// Run GLUT app containing Grapher app
	glApp app(label);
	app.run();
}