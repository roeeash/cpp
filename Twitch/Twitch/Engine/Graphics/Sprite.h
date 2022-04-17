#ifndef TWITCH_SPRITE
#define TWITCH_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include <iostream>
#include <string>

using namespace std;

class Sprite
{
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, float xPos, float yPos);
	
	void Update();
	void Render();

	void MoveTo(float x, float y);
	void MoveBy(float x,float y);
	void RotateTo(float x);
	void RotateBy(float x);
	void speedTo(float x);
	void speedBy(float x);

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();


	void setScale(float x);
	void setScale(float x, float y);

private:
	//Texture
	Texture texture;
	// x and y position
	float xPos;
	float yPos;
	float rot;
	float xScale;
	float yScale;
	float speed;

};

#endif
