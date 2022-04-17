#include "Sprite.h"
#include "../Engine.h"

Sprite::Sprite()
{
	xPos = 0;
	yPos = 0;
	rot = 0;
	speed = 100;
	texture = Texture();
	
}

Sprite::Sprite(string imagePath)
{
	xPos = 0;
	yPos = 0;
	rot = 0;
	speed = 100;
	texture = Texture(imagePath);
}

Sprite::Sprite(string imagePath, float _xPos, float _yPos)
{
	xPos = _xPos;
	yPos = _yPos;
	rot = 0;
	speed = 100;
	texture = Texture(imagePath);
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
	glTranslatef(xPos, yPos, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(xScale, yScale, 1);

	//Rendering
	//white with alpha - everything set to 1
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);

	//bottom left corner
	glTexCoord2f(0, 0); glVertex2f(0, 0);
	//bottom right corner
	glTexCoord2f(1, 0); glVertex2f(texture.GetWidth(), 0);
	//top right corner
	glTexCoord2f(1, 1); glVertex2f(texture.GetWidth(), texture.GetHeight());
	//top left corner
	glTexCoord2f(0, 1); glVertex2f(0 ,texture.GetHeight());

	//end our drawing
	glEnd();

	//isable the texture
	glDisable(GL_TEXTURE_2D);


}

//set sprite position
void Sprite::MoveTo(float x, float y) {
	xPos = x;
	yPos = y;
}

void Sprite::MoveBy(float x,float y) {
	xPos += (x * Engine::getDT());
	yPos += (y * Engine::getDT());
}


//set motoion
void Sprite::MoveLeft() {
	xPos -= (speed * Engine::getDT());

}
void Sprite::MoveRight() {
	xPos += (speed * Engine::getDT());
}
void Sprite::MoveUp() {
	yPos += (speed * Engine::getDT());
}
void Sprite::MoveDown() {
	yPos -= (speed * Engine::getDT());
}

void Sprite::RotateTo(float x)
{
	rot = x;
}
void Sprite::RotateBy(float x)
{
	rot += (x * Engine::getDT());
}
//set sprite scale
void Sprite::setScale(float x) {
	xScale = x;
	yScale = x;
}
void Sprite::setScale(float x, float y) {
	xScale = x;
	yScale = y;
}

//set speed
void Sprite::speedTo(float x) {
	speed = x;
}
void Sprite::speedBy(float x) {
	speed += x;
}



