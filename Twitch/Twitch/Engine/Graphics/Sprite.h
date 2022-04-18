#ifndef TWITCH_SPRITE
#define TWITCH_SPRITE

#include "GLFW/glfw3.h"
#include "../Math/Vector3.h"
#include "Texture.h"
#include <iostream>
#include <string>

using namespace std;

class Sprite
{
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, Vector3 v);
	
	void Update();
	void Render();

	void MoveTo(Vector3 v);
	void MoveBy(Vector3 v);
	void RotateTo(float x);
	void RotateBy(float x);
	void speedTo(float x);
	void speedBy(float x);

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();


	void setScale(float x);
	void setScale(Vector3 v);
	Vector3* getPos();
	float* getRot();
	Vector3* getScale();
	Vector3* getSize();

private:
	//Texture
	Texture texture;
	// x and y position
	Vector3 pos;
	float rot;
	Vector3 scale;
	float speed;
	Vector3 size;

};

#endif
