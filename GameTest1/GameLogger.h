#ifndef GAMELOGGER_H
#define GAMELOGGER_H

#include <string>
#include <sstream>
#include <windows.h>

class GameLogger
{
public:
	static GameLogger* Instance()
	{
		if (m_pInstance == 0)
		{
			m_pInstance = new GameLogger();
		}

		return m_pInstance;
	}

	void log(std::string msg);
	void log(std::stringstream& msg);
	void warn(std::string msg);
	void warn(std::stringstream& msg);
	void fatal(std::string msg, std::string file, int line);
	void fatal(std::stringstream& msg, std::string file, int line);

	void crash(std::string msg, std::string file, int line);
	void crash(std::stringstream& msg, std::string file, int line);

	void debug(std::string msg);
	void debug(std::stringstream& msg);

	void setDebug(bool debug);

private:

	GameLogger() 
	{
		this->m_bdebug = false;
		this->m_time = (LPSYSTEMTIME)malloc(sizeof(LPSYSTEMTIME));
	}

	~GameLogger() {}

	enum {BLACK, DARK_BLUE, DARK_GREEN, DARK_CYAN, DARK_RED, DARK_MAGENTA, DARK_YELLOW, GRAY, DARK_GREY, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE};

	void setConsoleColor(int color);
	void getCurrentTime(std::stringstream& dest);

	static GameLogger* m_pInstance;
	LPSYSTEMTIME m_time;

	bool m_bdebug;
};

#define LOG(msg) GameLogger::Instance()->log(msg)
#define WARN(msg) GameLogger::Instance()->warn(msg)
#define FATAL(msg) GameLogger::Instance()->fatal(msg, __FILE__, __LINE__)
#define CRASH(msg) GameLogger::Instance()->crash(msg, __FILE__, __LINE__)
#define DEBUG(msg) GameLogger::Instance()->debug(msg)

#endif