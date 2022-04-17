#include "Mouse.h"

//Initallize privates of static class Mouse
double Mouse::x = 0;
double Mouse::y = 0;
bool Mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };

//handle mouse position
void Mouse::mousePosCallback(GLFWwindow* window, double _x, double _y) {
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	x = _x;
	y = height - _y;
}
//handle button pressing
void Mouse::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button < 0) {
		return;
	}
	//if we didn't release and the button is not pressed
	if (action != GLFW_RELEASE && buttons[button] == false) {
		buttonsDown[button] = true;
		buttonsUp[button] = false;
	}
	//if we did release and the button is pressed
	if (action == GLFW_RELEASE && buttons[button] == true) {
		buttonsDown[button] = false;
		buttonsUp[button] = true;
	}

	buttons[button] = action != GLFW_RELEASE;


}
//getters
double Mouse::getMouseX() {
	return x;
}
double Mouse::getMouseY() {
	return y;
}

bool Mouse::ButtonDown(int button) {
	bool down = buttons[button];
	//clear the value
	buttons[button] = false;
	//return previous value
	return down;
}

bool Mouse::ButtonUp(int button) {
	bool up = buttons[button];
	//clear the value
	buttons[button] = false;
	//return previous value
	return up;
}

bool Mouse::Button(int button) {
	return buttons[button];
}
