#ifndef TWITCH_SPRITE
#define TWITCH_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "../Math/Vector3.h"

#include <iostream>
#include <string>
using namespace std;

class Sprite {
public:
	Sprite(); // constructor
	Sprite(string imagePath);
	Sprite(string imagePath, Vector3 _pos);

	void Update();
	void Render();
	
	void changeSpeedTo(float x);
	void changeSpeedBy(float x);

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void moveTo(Vector3 v);
	void moveBy(Vector3 v);

	void rotateTo(float x); // sets the rotation to x 
	void rotateBy(float x); // set the rotation by x 

	void SetScale(float x);
	void SetScale(Vector3 v);

	void FlipHorizontal();
	void FlipVertical();

	Vector3* getPos();
	float* GetRot();
	Vector3* getScale();
	Vector3* getSize();

private:
	Texture texture;
	float speed;
	Vector3 pos;
	float rot; // rotation
	Vector3 scale;
	Vector3 size;
};

#endif