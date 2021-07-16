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

private:
	Sprite sprite;
	Rigidbody rb;

	float flapForce;
	float minRot;
	float maxRot;
};
#endif
