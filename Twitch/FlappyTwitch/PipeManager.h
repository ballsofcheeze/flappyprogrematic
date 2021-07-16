#ifndef TWITCH_PIPEMANAGER
#define TWITCH_PIPEMANAGER

#include "Pipe.h"
#include "Flapper.h"
#include <vector>
class PipeManager {
public:
	PipeManager();
	~PipeManager();

	void Update();
	void Render();

	bool checkCollision(Flapper& flapper);

private:
	void createPipe();
	vector<Pipe*> pipes;

	float xSeparation;
	float minXSeparation;
	float ySeparation;
	float minYSeparation;
	float xSeparationSpeed;
	float ySeparationSpeed;

	int minSpawnY;
	int maxSpawnY;

	int totalPipes;
};
#endif

