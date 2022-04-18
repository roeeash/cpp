#include "Flapper.h"
#include "../Engine/Engine.h"
#include "../Engine/IO/Keyboard.h"
#include "../Engine/IO/Mouse.h"

Flapper::Flapper()
{
}

Flapper::Flapper(Sprite _sprite) 
{
	sprite = _sprite;
	rb.Initiallize(0.8f, -10, sprite.getPos(), sprite.getRot(), sprite.getScale(), sprite.getSize());
}

void Flapper::Update()
{
	sprite.Update();
	rb.Update();
}

void Flapper::Render()
{
	sprite.Render();
	//rb.Render(Vector3(1, 1, 1));
}

Sprite& Flapper::GetSprite()
{
	return sprite;
}

Rigidbody& Flapper::GetRB()
{
	return rb;
}
