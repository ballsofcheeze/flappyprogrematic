#include <iostream>
#include <time.h>
#include "Engine/Engine.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"
#include "Engine/Graphics/Sprite.h"
#include "FlappyTwitch/InputManager.h"
#include "FlappyTwitch/Flapper.h"
#include "FlappyTwitch/Pipe.h"
#include "FlappyTwitch/PipeManager.h"

using namespace std;

int main() {
	cout << "Hello, Twitch!" << endl;
	srand(time(NULL));

	Engine Engine;

	Engine.Initialize("Twitch!");

	Sprite testSprite = Sprite("Assets/Art/planeYellow3.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	testSprite.SetScale(0.8f);

	testSprite.SetScale(0.8f);
	Flapper player(testSprite);

	Pipe::Initialize();
	PipeManager pipeManager;

	InputManager im(&player);

	while (true) {
		Engine.Update();
		player.Update();
		pipeManager.Update();
		bool isColliding = pipeManager.checkCollision(player);
		cout << (isColliding ? "Colliding!" : "...") << endl;
		im.Update();
		//testSprite.SetPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY()); // the mouse values gets updated in engine.update(), in this function we then set our sprite to the mouse values given in engine.update 
		
		Engine.BeginRender(); // we have to put all sprite renders between beginrender and endrender (all visual changes are done in this area)
		player.Render();
		pipeManager.Render();
		Engine.EndRender();
	}
	return 0;
}
