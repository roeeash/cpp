#ifndef TWITCH_MOUSE
#define TWITCH_MOUSE

//we'll use this class as a static class since 
//you only ever have one mouse and only use one mouse
//and you never want to instantiate another one
#include "GLFW/glfw3.h"

class Mouse
{
public:
	//callback functions
	static void mousePosCallback(GLFWwindow* window, double _x, double _y);
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	
	//getters
	static double getMouseX();
	static double getMouseY();

	//get button state
	static bool ButtonUp(int button);
	static bool ButtonDown(int button);
	static bool Button(int button);

private:
	static double x;
	static double y;

	//to know if the mouse is currently held down, read buttons
	static bool buttons[];
	//to know if we just clicked a button, read buttonsDown
	static bool buttonsDown[];
	//to know if we just clicked a button, read buttonsUp
	static bool buttonsUp[];


};
#endif

