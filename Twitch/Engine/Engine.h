#ifndef TWITCH_ENGINE
#define TWITCH_ENGINE // makes sure that the header file is only defined once,

#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib") // tells the compiler to add our libname to the list of library dependencies

#include <iostream>
using namespace std;

class Engine {
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static float getDT();

	Engine();
	~Engine(); // this is a destructor, it destroys the instance to free up memory 

	bool Initialize(const char* windowTitle);

	void Update(); // Update state of everything in the game 
	void BeginRender(); // render all the new updates
	void EndRender(); // render all the new updates

private:
	static GLFWwindow* window; // a window object in GLFW

	static float dt; // the time it takes to render a frame
	float lastTime;
};

#endif
