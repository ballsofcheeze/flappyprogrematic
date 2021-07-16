#include "InputManager.h"

InputManager::InputManager(Flapper* _flapper) {
	flapper = _flapper;
}

void InputManager::Update() {

	if (Keyboard::keyDown(GLFW_KEY_SPACE) || Mouse::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {
		flapper->Flap();
	}
}