#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>

class Timer
{
public:
	Timer();

	void start();
	void restart();
	void stop();
	void pause();
	void unpause();

	Uint32 GetTicks();

	bool isStarted();
	bool isPaused();

private:

	Uint32 pausedTicks;
	Uint32 startTicks;

	bool started;
	bool paused;

};

#endif