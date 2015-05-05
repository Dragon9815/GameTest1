#include <iostream>
#include <conio.h>
#include <sstream>
#include <time.h>
#include <Windows.h>

#include "Game.h"
#include "GameLogger.h"
#include "Timer.h"

#define FPS 10
#define FRAME_TIME (1000/FPS)

int main(int argc, char* args[])
{
	Game game;
	Timer FPSTimer;

	bool quit = false;
	SDL_Event e;

	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			if (strcmp(args[i], "-debug") == 0)
			{
				GameLogger::Instance()->setDebug(true);
				DEBUG("Debug messages activated");
			}
			else
			{
				std::stringstream s;
				s << "Unknown Argument: " << args[i] << "";
				WARN(s.str());
			}
		}
	}

	game.init(SCREEN_WIDTH, SCREEN_HEIGHT);

	FPSTimer.start();
	Uint32 ticks;
	while (!quit)
	{
		FPSTimer.restart();
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		game.handleInput(e);
		game.update();
		game.render();

		ticks = FPSTimer.GetTicks();
		if (ticks < FRAME_TIME)
		{
			SDL_Delay(FRAME_TIME - ticks);
		}
	}

	return 0;
}