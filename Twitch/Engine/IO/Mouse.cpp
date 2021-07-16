#include "Mouse.h"

// because we have static data in the h file, we need to isntantiate them rn 

double Mouse::x = 0;
double Mouse::y = 0;

bool Mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };

void Mouse::MousePosCallBack(GLFWwindow* window, double _x, double _y) {

	int width, height;

	glfwGetFramebufferSize(window, &width, &height);

	x = _x;
	y = height - _y;
}

void Mouse::MouseButtonCallBack(GLFWwindow* window, int button, int action, int mods) {
	
	if (button < 0) {
		return;
	}

	if (action != GLFW_RELEASE && buttons[button] == false) {
		buttonsDown[button] = true; 
		buttonsUp[button] = false; // user just pressed our button
	} 

	if (action == GLFW_RELEASE && buttons[button] == true) {
		buttonsDown[button] = false;
		buttonsUp[button] = true; // user just pressed our button
	}

	buttons[button] = (action != GLFW_RELEASE); // if its not release, its gonna be true
}

double Mouse::getMouseX() {
	return x;
}

double Mouse::getMouseY() {
	return y;
}

bool Mouse::buttonDown(int button) {
	bool x = buttonsDown[button];
	buttonsDown[button] = false;
	return x;
}

bool Mouse::buttonUp(int button) {
	bool x = buttonsUp[button];
	buttonsUp[button] = false;
	return x;
}

bool Mouse::button(int button) {
	return buttons[button];
}
