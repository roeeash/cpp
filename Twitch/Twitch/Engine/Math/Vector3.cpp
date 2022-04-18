#include "Vector3.h"
//constructors

//empty constructor
Vector3::Vector3() {
	x = 0;
	y = 0;
	z = 0;
}

//copy constructor
Vector3::Vector3(const Vector3& other) {
	x = other.x;
	y = other.y;
	z = other.z;
}
Vector3::Vector3(float _x) {
	x = _x;
	y = _x;
	z = _x;
}

Vector3::Vector3(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
}

//operators

Vector3& Vector3::operator=(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;

	return *this;

}

Vector3 Vector3::operator+(const Vector3& other)
{
	return Vector3(x+other.x,y+other.y,z+other.z);
}

Vector3 Vector3::operator-(const Vector3& other)
{
	return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(const Vector3& other)
{
	return Vector3(x * other.x, y * other.y, z * other.z);
}

Vector3 Vector3::operator*(float scalar)
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}

bool Vector3::operator==(const Vector3& other)
{
	return (x==other.x && y ==other.y && z== other.z);
}

bool Vector3::operator!=(const Vector3& other)
{
	return (x != other.x || y != other.y || z != other.z);
}
