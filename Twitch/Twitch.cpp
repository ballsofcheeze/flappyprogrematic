#include "FlappyTwitch/GameManager.h"

#include <iostream>
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));

	GameManager gameManager;
	gameManager.Start();

	return 0;
}
