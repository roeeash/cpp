#include "Sprite.h"
#include "../Engine.h"


Sprite::Sprite()
{
	pos = Vector3(0);
	rot = 0;
	speed = 100;
	scale = Vector3(0);
	texture = Texture();
	size = Vector3(0);
	
}

Sprite::Sprite(string imagePath)
{
	pos = Vector3(0);
	rot = 0;
	speed = 100;
	scale = Vector3(1);
	texture = Texture(imagePath);
	size = ((float)texture.GetWidth(), (float)texture.GetHeight(), 1);
}

Sprite::Sprite(string imagePath, Vector3 v)
{
	pos = Vector3(v);
	rot = 0;
	speed = 100;
	scale = Vector3(1);
	texture = Texture(imagePath);
	size = ((float)texture.GetWidth(), (float)texture.GetHeight(), 1);
}

void Sprite::Update() {
	//rot+= 0.01;
}
void Sprite::Render() {
	
	// Enable the texture
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//Bind to Texture id
	glBindTexture(GL_TEXTURE_2D, texture.GetID());
	//clear the screen
	glLoadIdentity();

	//TRANSLATE -> ROTATE -> SCALE
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(scale.x, scale.y, 1);

	//Rendering
	//white with alpha - everything set to 1
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	{
		//bottom left corner
		glTexCoord2f(0, 0); glVertex2i(0, 0);
		//bottom right corner
		glTexCoord2f(1, 0); glVertex2i(texture.GetWidth(), 0);
		//top right corner
		glTexCoord2f(1, 1); glVertex2i(texture.GetWidth(), texture.GetHeight());
		//top left corner
		glTexCoord2f(0, 1); glVertex2i(0, texture.GetHeight());
	}
	//end our drawing
	glEnd();

	//isable the texture
	glDisable(GL_TEXTURE_2D);


}

//set sprite position
void Sprite::MoveTo(Vector3 v) {
	pos = v;
}

void Sprite::MoveBy(Vector3 v) {
	pos = pos + (v * Engine::getDT());
}


//set motoion
void Sprite::MoveLeft() {
	pos = pos - Vector3((speed * Engine::getDT()), 0, 0);

}
void Sprite::MoveRight() {
	pos = pos + Vector3((speed * Engine::getDT()),0,0);
}
void Sprite::MoveUp() {
	pos = pos + Vector3(0,(speed * Engine::getDT()), 0);
}
void Sprite::MoveDown() {
	pos = pos - Vector3(0, (speed * Engine::getDT()), 0);
}

void Sprite::RotateTo(float x)
{
	rot = x;
}
void Sprite::RotateBy(float x)
{
	rot += (x * Engine::getDT());
}

//set speed
void Sprite::speedTo(float x) {
	speed = x;
}
void Sprite::speedBy(float x) {
	speed += x;
}



//set sprite scale
void Sprite::setScale(float x) {
	scale = Vector3(x);
}
void Sprite::setScale(Vector3 v) {
	scale = v;
}

//getters
Vector3* Sprite :: getPos() {
	return &pos;
}
float* Sprite::getRot() {
	return &rot;
}
Vector3* Sprite::getScale() {
	return &scale;
}
Vector3* Sprite::getSize() {
	return &size;
}
