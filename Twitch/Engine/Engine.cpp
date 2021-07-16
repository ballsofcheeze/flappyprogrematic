#include "Engine.h"
#include "IO/Mouse.h"
#include "IO/Keyboard.h"

int Engine::SCREEN_WIDTH = 1024; // they're static so its good to initialise them rn 
int Engine::SCREEN_HEIGHT = 768;
GLFWwindow* Engine::window = NULL;
float Engine::dt = 0;

Engine::Engine() {

}

Engine::~Engine() {

}

bool Engine::Initialize(const char* windowTitle) {

	if (!glfwInit()) { // initializes our library 
		cout << "Error initialise glfw!" << endl;
		return false;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);
	if (window == NULL) {
		cout << "Error creating window" << endl;
		return false;
	}

	//OpenGL setup (an open graphics library (installed with NupenGL))
	glfwMakeContextCurrent(window); //sets the "context" of openGL, it stores all the state associated with the isntance of openGL, ie. it contains all of OpenGL 
	int width, height;
	glfwGetFramebufferSize(window, &width, &height); // & is the poitner stuff (franebuffer is a memory buffer representing all the pixels in a video frame) 
	glfwSwapInterval(1); // reduces flickering

	glfwSetCursorPosCallback(window, Mouse::MousePosCallBack);
	glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallBack);
	glfwSetKeyCallback(window, Keyboard::KeyCallBack);

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor()); // gives our context the actual monitor 
	int xPos = (mode->width - SCREEN_HEIGHT) / 2;
	int yPos = (mode->height - SCREEN_WIDTH) / 2;
	glfwSetWindowPos(window, xPos, yPos); // sets the window to the centre of the screen

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -10, 10); // the location of the camera 
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW); // all functions we write after that affects this matrix mode 

	// Alpha Blending 
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	lastTime = (float)glfwGetTime();

	return true; // everything has been initialised 
}

void Engine::Update() {
	float now = (float)glfwGetTime();
	dt = (now - lastTime);
	lastTime = now; // shows the frame rate essentially 
	glfwPollEvents(); // lets GLFW handle all the events like mouse movements etc.
}

void Engine::BeginRender() {
	glClearColor(0, 1, 0, 1); // clear oru backbuffer with a blue colour 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear colour and depth

}

void Engine::EndRender() {
	glfwSwapBuffers(window);
}

float Engine::getDT() {
	return (float)dt;
}