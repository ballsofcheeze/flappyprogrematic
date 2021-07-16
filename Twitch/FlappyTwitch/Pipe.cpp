#include "Pipe.h"
#include "../Engine/Math/Rect.h"
#include "../Engine/Math/Math.h"
#include "../Engine/Engine.h"

Sprite* Pipe::pipeSprite = NULL;

void Pipe::Initialize() {
	pipeSprite = new Sprite("Assets/Art/pipe.png");
	pipeSprite->SetScale(Vector3(0.1f, 0.5f, 1));
}

Pipe::Pipe() {
	if (!pipeSprite) {
		cout << "Pipe hasnt been initialised yet" << endl;
		return;
	}

	topSprite = Sprite(*pipeSprite);
	botSprite = Sprite(*pipeSprite);

	gap = 350;
	speed = 200;
}

Pipe::Pipe(Vector3 _pos) : Pipe() {

	if (!pipeSprite) {
		return;
	}

	pos = _pos + Vector3(getWidth(), 0, 0);

	UpdatePos();
	topSprite.FlipVertical();

	Rect topRC = Rect();
	topRC.SetSize(Vector3(Math::Abs(topSprite.getSize()->x * topSprite.getScale()->x), Math::Abs(topSprite.getSize()->y * topSprite.getScale()->y), 1));	
	topRB = Rigidbody();
	topRB.Initialize(1, 0, topSprite.getPos(), topSprite.GetRot(), topSprite.getScale(), topSprite.getSize(), topRC);

	Rect botRC = Rect();
	botRC.SetSize(Vector3(Math::Abs(botSprite.getSize()->x * botSprite.getScale()->x), Math::Abs(botSprite.getSize()->y * botSprite.getScale()->y), 1));
	botRB = Rigidbody();
	botRB.Initialize(1, 0, botSprite.getPos(), botSprite.GetRot(), botSprite.getScale(), botSprite.getSize(), botRC);

	topRB.AddForce(Vector3(-speed, 0, 0));
	botRB.AddForce(Vector3(-speed, 0, 0));
}

void Pipe::update() {
	topRB.Update();
	botRB.Update();
}

void Pipe::render() {
	topSprite.Render();
	botSprite.Render();
	topRB.Render(Vector3(255,0,0));
	botRB.Render(Vector3(0,0,255));
}

void Pipe::MoveTo(Vector3 to) {
	
	pos = to;
	UpdatePos();
}

void Pipe::MoveBy(Vector3 by) {
	pos = pos + by;
	UpdatePos();
}


void Pipe::UpdatePos() {

	Vector3 topPos = pos;
	topPos.y += (gap / 2) + Math::Abs(topSprite.getSize()->y * topSprite.getScale()->y / 2);
	topSprite.moveTo(topPos);

	Vector3 botPos = pos;
	botPos.y -= (gap / 2) + Math::Abs(botSprite.getSize()->y * botSprite.getScale()->y / 2);
	botSprite.moveTo(botPos);
}

Rigidbody Pipe::getTopRB() {
	return topRB;
}

Rigidbody Pipe::getBotRB() {
	return botRB;
}

float Pipe::getX() {
	return topSprite.getPos()->x;
}

void Pipe::setGap(float _gap) {
	gap = _gap;
	UpdatePos(); 
}

float Pipe::getWidth() {
	return topSprite.getSize()->x * topSprite.getScale()->x;
}