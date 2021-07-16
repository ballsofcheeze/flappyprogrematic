#ifndef TWITCH_MOUSE
#define TWITCH_MOUSE

#include "GLFW/glfw3.h"

class Mouse { // make a mouse class statically as there is only one so you dont need ot make like 3 mouse classes 
public:
	static void MousePosCallBack(GLFWwindow* window, double _x, double _y);
	static void MouseButtonCallBack(GLFWwindow* window, int button, int action, int mods);

	static double getMouseX();
	static double getMouseY();

	static bool buttonDown(int button);
	static bool buttonUp(int button);
	static bool button(int button);


private:
	static double x;
	static double y;

	static bool buttons[]; // if its currently down?
	static bool buttonsDown[]; // if it was just clicked 
	static bool buttonsUp[]; // if it was just released 

};
#endif 