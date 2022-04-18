#ifndef TWITCH_VECTOR3
#define TWITCH_VECTOR3	

class Vector3
{
public:
	//constuctors
	Vector3();
	Vector3(const Vector3& other);
	Vector3(float _x);
	Vector3(float _x, float _y, float _z);

	//operators
	Vector3& operator= (const Vector3& other);
	Vector3 operator+(const Vector3& other);
	Vector3 operator-(const Vector3& other);
	Vector3 operator*(const Vector3& other);
	Vector3 operator*(float scalar);
	bool operator==(const Vector3& other);
	bool operator!=(const Vector3& other);

	//"privates" we want to group 3 floats
	//but keep the code relatively similar and clean
	float x, y, z;

};

#endif
