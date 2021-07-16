#ifndef TWITCH_KEYBOARD
#define TWITCH_KEYBOARD

#include "GLFW/glfw3.h"

class Keyboard { // make a keyboard class statically as there is only one so you dont need ot make like 3 mouse classes 
public:
	static void KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);

	static bool keyDown(int key);
	static bool keyUp(int key);
	static bool key(int key);
private:
	static bool keys[];
	static bool keysDown[];
	static bool keysUp[];
};
#endif #pragma once
