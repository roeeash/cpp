#include <iostream>
#include "Engine.h"
#include "IO/Mouse.h"
#include "IO/Keyboard.h"

using namespace std;

//variables
int Engine :: SCREEN_WIDTH = 1024;
int Engine:: SCREEN_HEIGHT = 768;
GLFWwindow* Engine:: window = NULL;
float Engine::dt = 0;

//constructor
Engine::Engine() {

}
//deconstructor
Engine::~Engine()
{
}
bool Engine::Initiallize(char* windowTitle) {

	//if there's an init error
	if (!glfwInit()) {
		cout << "Error initallizing GLFW" << endl;
		return false;
	}
	//create glfw window
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);
	if (window == NULL) {
		cout << "Error creating window" << endl;
		return false;
	}
	//GLFW Setup - set context to window
	glfwMakeContextCurrent(window);
	int width, height;

	//passing by refernece so that get frame buffer size
	//will change width and height

	glfwGetFramebufferSize(window, &width, &height);
	
	//swap front and back interval, 
	//draw on back interval then swap to what the user sees
	glfwSwapInterval(1);

	// set mouse position callback
	glfwSetCursorPosCallback(window, Mouse::mousePosCallback);

	// set mouse button callback
	glfwSetMouseButtonCallback(window, Mouse::mouseButtonCallback);

	// set mouse position callback
	glfwSetKeyCallback(window, Keyboard::keyCallback);


	
	// using this will allow us to guarentee that our video
	//is always centered around the monitor itself
	const GLFWvidmode* videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	int xPos = (videoMode->width- SCREEN_WIDTH) / 2;
	int yPos = (videoMode->height - SCREEN_HEIGHT) / 2;
	
	//set window position in the middle
	glfwSetWindowPos(window, xPos, yPos);

	//GL Setup - open gl is a state machine, any function we call
	//performs out of the current state that we're on
	//Viewport
	
	//set view parameters
	glViewport(0, 0, width, height);
	//specifies which matrix is the current matrix
	glMatrixMode(GL_PROJECTION);

	//replace everything on screen with identitty("empty") matrix
	glLoadIdentity();

	//as x increases, we move right, as y increases we move down
	glOrtho(0, width, 0, height, -10, 10);

	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);
	//Alpha Blending - Background color blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//set lastTime to end of last action
	lastTime = (float)glfwGetTime();
	
	return true;

}

void Engine::Update() {
	
	//calculate delta time
	float now = (float)glfwGetTime();
	dt = (now - lastTime);
	lastTime = now;

	//track and perform changes 
	glfwPollEvents();
}


void Engine::BeginRender() {
	// clear screen and color it blue
	glClearColor(0, 1, 0, 1);
	//clear both color and dpeth bits
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


}

void Engine::EndRender() {

	//swap the buffer to what we drew on
	glfwSwapBuffers(window);
}

float Engine::getDT() {
	return(float) dt;
}