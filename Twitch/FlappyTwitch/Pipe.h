#ifndef TWITCH_PIPE
#define TWITCH_PIPE
#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/Rigidbody.h"
#include "../Engine/Math/Vector3.h"

class Pipe {
public:
	static Sprite* pipeSprite;
	static void Initialize();

	void setGap(float _gap);

	Pipe();
	Pipe(Vector3 _pos);
	void update();
	void render();

	void MoveTo(Vector3 to);
	void MoveBy(Vector3 by);

	Rigidbody getTopRB();
	Rigidbody getBotRB();

	float getX();
	float getWidth();
private:

	void UpdatePos();

	Sprite topSprite;
	Sprite botSprite;

	Rigidbody topRB;
	Rigidbody botRB;

	Vector3 pos;

	float gap;
	float speed;
};
#endif