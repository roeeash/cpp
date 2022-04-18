#include "Rigidbody.h"
#include "../Engine.h"
#include "../Math/Vector3.h"

Rigidbody::Rigidbody() {
	friction = 1;
	gravity = 0;
}


void Rigidbody::Initiallize(float _friction, float _gravity,
	Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size)
{
	friction = _friction;
	gravity = _gravity;
	pos = _pos;
	scale = _scale;
	rot = _rot;
	size = _size;
}

void Rigidbody::Update()
{
	velocity.x *= friction;
	velocity.y -= gravity;

	*pos = *pos + (velocity*Engine::getDT());

}

void Rigidbody::Render(Vector3 c)
{
	//clear canvas first
	glLoadIdentity();
	//translate - move to pos
	glTranslatef(pos->x, pos->y, pos->z);
	//rotate
	glRotatef(*rot, 0, 0, 1);
	//scale
	glScalef(scale->x, scale->y, scale->z);
	//Rendering
	//white with alpha - everything set to 1
	glColor4f(c.x, c.y, c.z, 1);
	glBegin(GL_LINES);
	{
		//bottom left corner to bottom right corner
		glVertex2i(0, 0);
		glVertex2i((int)size->x, 0);


		//bottom right corner to top right corner
		glVertex2i((int)size->x, 0);
		glVertex2i((int)size->x, (int)size->y);

		//top right corner to top left corner
		glVertex2i((int)size->x, (int)size->y);
		glVertex2i(0, (int)size->y);

		//top left corner to  left corner
		glVertex2i(0, (int)size->y);
		glVertex2i(0, 0);
	}
	//end our drawing
	glEnd();
}

void Rigidbody::AddForce(Vector3 f) {
	velocity = velocity + f;
}