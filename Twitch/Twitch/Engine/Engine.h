#ifndef TWITCH_ENGINE
#define TWITCH_ENGINE

#include "GLFW/glfw3.h"
#pragma comment(lib,"opengl32.lib")

class Engine {
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static float getDT();

	Engine();
	~Engine();

	bool Initiallize(char* windowTitle);
	void Update();
	void BeginRender();
	void EndRender();

private:
	static GLFWwindow* window;
	// delta time = the difference in time
	static float dt;
	//lastTime = last time measured
	float lastTime;

};
#endif

