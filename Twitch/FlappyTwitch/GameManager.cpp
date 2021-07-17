#include "GameManager.h"

GameManager::GameManager() {

	mEngine = new Engine();
	mEngine->Initialize("Twitch!");

	Sprite testSprite = Sprite("Assets/Art/planeYellow3.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	testSprite.SetScale(0.8f);

	mFlapper = new Flapper(testSprite);
	mPipeManager = new PipeManager();

	mStartSprite = Sprite("Assets/Art/play.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	mStartSprite.SetScale(0.5f);

	mGameOverSprite = Sprite("Assets/Art/gameover.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	mGameOverSprite.SetScale(0.5f);

	mState = State::START;
}

GameManager::~GameManager() {
	delete mEngine;
	delete mFlapper;
	delete mPipeManager;
}
void GameManager::Start() {
	while (true) {
		mEngine->Update();

		switch (mState) {
		case State::START:
		{
			mEngine->BeginRender(); // we have to put all sprite renders between beginrender and endrender (all visual changes are done in this area)
			mStartSprite.Render(); 
			mEngine->EndRender();

			if (Keyboard::keyDown(GLFW_KEY_SPACE) || Mouse::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {
				SetState(State::GAMEPLAY);
			}
		}
		break;
		case State::GAMEPLAY:
		{ 
			mFlapper->Update();
			mPipeManager->Update();

			mEngine->BeginRender(); // we have to put all sprite renders between beginrender and endrender (all visual changes are done in this area)
			mFlapper->Render();
			mPipeManager->Render();
			mEngine->EndRender();

			bool isDead = mPipeManager->checkCollision(*mFlapper);
			if (mFlapper->getSprite().getPos()->y < 0 || mFlapper->getSprite().getPos()->y > Engine::SCREEN_HEIGHT) {
				isDead = true;
			}
			if (isDead) {
				SetState(State::GAMEOVER);
			}

		}
		break;
		case State::GAMEOVER:
		{
			mEngine->BeginRender(); // we have to put all sprite renders between beginrender and endrender (all visual changes are done in this area)
			mFlapper->Render();
			mPipeManager->Render();
			mGameOverSprite.Render();
			mEngine->EndRender();

			if (Keyboard::keyDown(GLFW_KEY_SPACE) || Mouse::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {
				SetState(State::START);
			}

		}
		break;
		default:
			cout << "Unhandled game State: " << static_cast<int>(mState) << endl;
			break; 
		}
	}
}

void GameManager::SetState(State state) {

	mState = state;

	if (mState == State::START) {
		mFlapper->Reset();
		mPipeManager->Reset();
	}
}