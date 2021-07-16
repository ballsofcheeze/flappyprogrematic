#ifndef TWITCH_VECTOR3
#define TWITCH_VECTOR3

#include "GLFW/glfw3.h"

class Vector3 { // an entity that'll hold 3 values for us, ie. rerpesenting position, color etc.
public:
	static float Dot(const Vector3& a, const Vector3& b);
	static Vector3 Project(const Vector3& a, const Vector3& b);

	Vector3();
	Vector3(const Vector3& other);
	Vector3(float _x);
	Vector3(float _x, float _y, float _z);

	Vector3& operator=(const Vector3& other);
	Vector3 operator+(const Vector3& other);
	Vector3 operator-(const Vector3& other);
	Vector3 operator*(const Vector3& other);
	Vector3 operator*(float _x);

	bool operator==(const Vector3& other);
	bool operator!=(const Vector3& other);

	float x;
	float y;
	float z;
private:
};
#endif 