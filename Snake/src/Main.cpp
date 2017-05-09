#include "Game.h"

#if _DEBUG
int32 main(int32 argc, char* argv[]) {
#else
#include <Windows.h>
int32 CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int32 nCmdShow) {
#endif
	while (Game::Instance()->IsRunning()) {
		Game::Instance()->HandleEvents();
		Game::Instance()->Update();
		Game::Instance()->LateUpdate();
		Game::Instance()->Draw();
	}

	return 0;
}
