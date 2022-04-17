#ifndef TWITCH_KEYBOARD
#define TWITCH_KEYBOARD

#include "GLFW/glfw3.h"

class Keyboard
{
public:
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	//get key state
	static bool KeyUp(int key);
	static bool KeyDown(int key);
	static bool Key(int key);
private:
	static bool keys[];
	static bool keysUp[];
	static bool keysDown[];
};
#endif

