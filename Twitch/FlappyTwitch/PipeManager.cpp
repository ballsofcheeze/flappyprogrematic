#include "PipeManager.h"
#include "../Engine/Engine.h"
#include "Pipe.h"
#include "../Engine/Physics/Rigidbody.h"

PipeManager::PipeManager() : xSeparation(xStartSeparation),
		xStartSeparation(500), 
		yStartSeparation(500),
		ySeparation(yStartSeparation),
		minXSeparation(100),
		minYSeparation(200), 
		xSeparationSpeed(20),
		ySeparationSpeed(20),
		minSpawnY(300), 
		maxSpawnY(Engine::SCREEN_HEIGHT - 300),
		totalPipes(0) {
	Pipe::Initialize();
	createPipe();
}

PipeManager::~PipeManager() {
	for (unsigned int i = 0; i < pipes.size(); i++) {
		delete pipes[i];
	}
}

void PipeManager::Update() {
	vector<int> pipesToDelete;
	for (unsigned int i = 0; i < pipes.size(); i++) {
		pipes[i]->update();
		if (pipes[i]->getX() < -(pipes[i]->getWidth()/2)) {
			pipesToDelete.push_back(i);
		}

		if (i == pipes.size() - 1) {
			if (pipes[i]->getX() < Engine::SCREEN_WIDTH - xSeparation) {
				createPipe();
			}
		}
	}

	for (unsigned int i = 0; i < pipesToDelete.size(); i++) {
		delete pipes[pipesToDelete[i]];
		pipes.erase(pipes.begin() + pipesToDelete[i]);

	}
}

void PipeManager::Render() {
	for (unsigned int i = 0; i < pipes.size(); i++) {
		pipes[i]->render();
	}
}

bool PipeManager::checkCollision(Flapper& flapper) {

	bool isColliding = false;

	for (unsigned int i = 0; i < pipes.size(); i++) {
		isColliding =  Rigidbody::isColliding(flapper.GetRB(), pipes[i]->getTopRB()) || Rigidbody::isColliding(flapper.GetRB(), pipes[i]->getBotRB());
		if (isColliding)
			break;
	}

	return isColliding;
}

void PipeManager::createPipe() {
	float spawnY = rand() % (maxSpawnY - minSpawnY) + minSpawnY;
	Pipe* pipe = new Pipe(Vector3(Engine::SCREEN_WIDTH + 200, spawnY, 0));
	pipe->setGap(ySeparation);

	pipes.push_back(pipe);		
	totalPipes++;

	if (totalPipes % 2 == 0) {
		if (xSeparation > minXSeparation + xSeparationSpeed) {
			xSeparation -= xSeparationSpeed;
		}
		if (ySeparation > minYSeparation + ySeparationSpeed) {
			ySeparation -= ySeparationSpeed;
		}

	}
}

void PipeManager::Reset() {
	for (unsigned int i = 0; i < pipes.size(); i++) {
		delete pipes[i];
	}
	pipes.clear();

	xSeparation = xStartSeparation;
	ySeparation = yStartSeparation;
	totalPipes = 0;

	createPipe();
}