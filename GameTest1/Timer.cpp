#include "Timer.h"

Timer::Timer()
{

}

void Timer::start()
{
	if (!this->started)
	{
		this->startTicks = SDL_GetTicks();
		this->pausedTicks = 0;
		this->started = true;
		this->paused = false;
	}
}

void Timer::restart()
{
	this->startTicks = SDL_GetTicks();
	this->pausedTicks = 0;
	this->started = true;
	this->paused = false;
}

void Timer::stop()
{
	if (this->started)
	{
		this->started = false;
		this->paused = false;
	}
}

void Timer::pause()
{
	if (!this->paused && this->started)
	{
		this->pausedTicks = SDL_GetTicks() - this->startTicks;
		this->startTicks = 0;
		this->paused = true;
	}
}

void Timer::unpause()
{
	if (this->paused && this->started)
	{
		this->startTicks = SDL_GetTicks() - this->pausedTicks;
		this->pausedTicks = false;

		this->paused = false;
	}
}

Uint32 Timer::GetTicks()
{
	Uint32 time = 0;

	if (this->started)
	{
		if (this->paused)
		{
			time = this->pausedTicks;
		}
		else
		{
			time = SDL_GetTicks() - this->startTicks;
		}
	}

	return time;
}

bool Timer::isStarted()
{
	return this->started;
}

bool Timer::isPaused()
{
	return this->paused;
}