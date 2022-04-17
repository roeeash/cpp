#include "Keyboard.h"

//init privates
bool Keyboard::keys[GLFW_KEY_LAST] = {0};
bool Keyboard::keysDown[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keysUp[GLFW_KEY_LAST] = { 0 };

//handle key event

void Keyboard::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	//handle error
	if (key < 0) {
		return;
	}
	// handle if a key is pressed
	if (action != GLFW_RELEASE && keys[key] == false) {
		keysDown[key] = true;
		keysUp[key] = false;
	}
	// handle if a key is released
	if (action == GLFW_RELEASE && keys[key] == true) {
		keysUp[key] = true;
		keysDown[key] = false;

	}
	//set key value
	keys[key] = action != GLFW_RELEASE;
}

//get key state
bool Keyboard::KeyDown(int key) {
	bool down = keys[key];
	keys[key] = false;
	return down;

}

bool Keyboard::KeyUp(int key) {
	bool up = keys[key];
	keys[key] = false;
	return up;

}
bool Keyboard::Key(int key) {
	return keys[key];

}



