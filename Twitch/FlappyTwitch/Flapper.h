#ifndef TWITCH_FLAPPER
#define TWITCH_FLAPPER
#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/Rigidbody.h"

class Flapper {
public:

	Flapper();
	Flapper(Sprite _sprite);

	void Update();
	void Render();
	void Flap();

	Sprite& getSprite();
	Rigidbody& GetRB();

	void Reset();

private:
	Sprite sprite;
	Rigidbody rb;

	void HandleInput();
	float flapForce;
	float minRot;
	float maxRot;
};
#endif
