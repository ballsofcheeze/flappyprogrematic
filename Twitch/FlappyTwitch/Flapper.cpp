#include "Flapper.h"
#include "../Engine/Engine.h"
#include "../Engine/Math/Rect.h"
#include <iostream>
using namespace std;

Flapper::Flapper() {
	flapForce = 500;
	maxRot = 30;
	minRot = -maxRot;
}

Flapper::Flapper(Sprite _sprite) : Flapper() {
	sprite = _sprite;
	Rect boundingRect = Rect();
	Vector3 sizeOffset(0.8, 0.8, 1);
	boundingRect.SetSize(*sprite.getSize() * *sprite.getScale() * sizeOffset);
	rb.Initialize(0.8f, -10, sprite.getPos(), sprite.GetRot(), sprite.getScale(), sprite.getSize(), boundingRect);
}

void Flapper::Update() {
	sprite.Update();
	rb.Update();

	float yVel = rb.getVel().y;
	if (flapForce == 0) {
		cout << "Uh oh...!" << endl;
		flapForce = 750;
	}
	float newRot = maxRot / flapForce *yVel;
	sprite.rotateTo(newRot);
}

void Flapper::Render() {
	sprite.Render();
	rb.Render(Vector3(0, 0, 0));
}

void Flapper::Flap() {
	rb.SetVel(Vector3(0, flapForce, 0));
	cout << maxRot << endl;
	sprite.rotateTo(maxRot);
}

Sprite& Flapper::getSprite() {
	return sprite;
}

Rigidbody& Flapper::GetRB() {
	return rb;
}