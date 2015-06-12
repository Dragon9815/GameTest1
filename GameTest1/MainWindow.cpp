#include <iostream>
#include <conio.h>
#include <sstream>
#include <time.h>
#include <Windows.h>
#include <thread>

#include "Game.h"
#include "GameLogger.h"
#include "Timer.h"
#include "defs.h"

#define FPS 10
#define FRAME_TIME (1000/FPS)

bool quit;
Game game;
Timer FPSTimer;

void handleInput();
void render();

int main(int argc, char* args[])
{
	SDL_Event e;
	Uint32 ticks;

	quit = false;


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

	//std::thread inputThread(handleInput);
	//std::thread renderThread(render);
	
	while (!quit)
	{
		FPSTimer.restart();

		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			if (e.type == SDL_MOUSEWHEEL)
			{
				//LOG(std::to_string(e.wheel.y));
				//LOG(std::to_string(e.wheel.x));
			}
			game.handleInput(e);
		}

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

/*void handleInput()
{
	

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}

		if (e.type == SDL_MOUSEWHEEL)
		{
			LOG(std::to_string(e.wheel.y));
			LOG(std::to_string(e.wheel.x));
		}
		game.handleInput(e);
	}
}

void render()
{
	Uint32 ticks;

	FPSTimer.restart();

	game.update();
	game.render();

	ticks = FPSTimer.GetTicks();
	if (ticks < FRAME_TIME)
	{
		SDL_Delay(FRAME_TIME - ticks);
	}
}*/