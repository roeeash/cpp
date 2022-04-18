#ifndef TWITCH_RIGIDBODY
#define TWITCH_RIGIDBODY

#include "../Math/Vector3.h"

//physics rigid body class
class Rigidbody
{
public:
	Rigidbody();

	//class methods
	void Initiallize(float _friction, float _gravity,
		Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size);

	void Update();
	void Render(Vector3 c);
	void AddForce(Vector3 f);

private:
	//sprite characteristics
	Vector3* pos;
	Vector3* scale;
	float* rot;
	Vector3* size;
	
	//physics related privates
	float gravity;
	float friction;
	Vector3 velocity;

};

#endif

