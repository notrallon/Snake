#include "Game.h"

int main() {
	while (Game::Instance()->IsRunning()) {
		Game::Instance()->HandleEvents();
		Game::Instance()->Update();
		Game::Instance()->Draw();
		Game::Instance()->LateUpdate();
	}

	return 0;
}
