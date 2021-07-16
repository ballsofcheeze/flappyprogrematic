#include "Sprite.h"
#include "../Engine.h"
#include "../Math/Vector3.h"

#include <iostream>
using namespace std;

Sprite::Sprite() {
	pos = Vector3(0);
	rot = 0;
	scale = Vector3(1);
	size = Vector3(0);
	texture = Texture();
	speed = 100;
	 
}

Sprite::Sprite(string imagePath) {
	texture = Texture(imagePath);
	rot = 0;
	pos = Vector3(0);
	scale = Vector3(1);
	size = Vector3((float)texture.GetWidth(), (float)texture.GetHeight(), 1);
	speed = 100;
}

Sprite::Sprite(string imagePath, Vector3 v) {
	pos = v;
	rot = 0;
	texture = Texture(imagePath);
	scale = Vector3(1);
	size = Vector3((float)texture.GetWidth(), (float)texture.GetHeight(), 1);
	speed = 100;
}

void Sprite::Update() {
	//cout << pos.x << pos.y << endl;
}

void Sprite::Render() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.GetID()); // bind our sprites id to the GL_TEXTURE_2D
	glLoadIdentity();

	//TRANSLATE -> ROTATE -> SCALE (order for moving stuff around)

	glTranslatef(pos.x, pos.y, 0); // sets our current gl coords to xpos, ypos, 0 (0 is the z axis which is unnecessary)
	glRotatef(rot, 0, 0, 1);
	glScalef(scale.x, scale.y, 1);
	//rendering 
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS); // draw quads
	{
		glTexCoord2f(0, 0); glVertex2i(-texture.GetWidth()/2, -texture.GetHeight()/2);
		glTexCoord2f(1, 0); glVertex2i(texture.GetWidth()/2, -texture.GetHeight() / 2);
		glTexCoord2f(1, 1); glVertex2i(texture.GetWidth()/2, texture.GetHeight()/2);
		glTexCoord2f(0, 1); glVertex2i(-texture.GetWidth()/2, texture.GetHeight()/2);
	}
	// grabs each corner of our texture, (ie. (0,0) is our bottom left corner
	glEnd(); 

	glDisable(GL_TEXTURE_2D);
}

void Sprite::changeSpeedTo(float x) {
	speed = x;
}

void Sprite::changeSpeedBy(float x) {
	speed += x;
}

void Sprite::moveBy(Vector3 v) {
	pos = pos + (v * Engine::getDT());
}

void Sprite::MoveLeft() {
	pos = pos - Vector3((speed * Engine::getDT()), 0, 0);
}

void Sprite::MoveRight() {
	pos = pos + Vector3((speed * Engine::getDT()), 0, 0);
}

void Sprite::MoveUp() {
	pos = pos + Vector3(0, (speed * Engine::getDT()), 0);
}

void Sprite::MoveDown() {
	pos = pos - Vector3(0, (speed * Engine::getDT()), 0);
}
void Sprite::moveTo(Vector3 v) {
	pos = v; 
}

void Sprite::rotateBy(float x) {
	rot += (x * Engine::getDT());
}

void Sprite::rotateTo(float x) {
	rot = x;
}

void Sprite::SetScale(float x) {
	scale = Vector3(x, x, 0);
}

void Sprite::SetScale(Vector3 v) {
	scale = v;
}

Vector3* Sprite::getPos() {
	return &pos;
}

float* Sprite::GetRot() {
	return &rot;
}

Vector3* Sprite::getScale() {
	return &scale;
}

Vector3* Sprite::getSize() {
	return &size;
}

void Sprite::FlipHorizontal() {
	scale.x = -scale.x;
}

void Sprite::FlipVertical() {
	scale.y = -scale.y;
}