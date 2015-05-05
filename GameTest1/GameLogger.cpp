#include "GameLogger.h"
#include <windows.h>
#include <iostream>
#include <sstream>
#include <conio.h>

GameLogger* GameLogger::m_pInstance = 0;

void GameLogger::setConsoleColor(int color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
}

void GameLogger::log(std::string msg)
{
	// Farbe: Weiß
	this->setConsoleColor(WHITE);
	std::stringstream s;
	this->getCurrentTime(s);

	s << ": [MSG] " << msg << std::endl;
	std::cout << s.str();
}

void GameLogger::log(std::stringstream& msg)
{
	this->log(msg.str());
}


void GameLogger::warn(std::string msg)
{
	// Farbe: Gelb
	this->setConsoleColor(YELLOW);
	std::stringstream s;
	this->getCurrentTime(s);

	s << ": [WARNING] " << msg << std::endl;
	std::cout << s.str();
}

void GameLogger::warn(std::stringstream& msg)
{
	this->warn(msg.str());
}


void GameLogger::fatal(std::string msg, std::string file, int line)
{
	// Farbe: Rot
	this->setConsoleColor(RED);
	std::stringstream s;
	this->getCurrentTime(s);

	s << ": [FATAL] " << msg << std::endl;
	std::cout << s.str();
}

void GameLogger::fatal(std::stringstream& msg, std::string file, int line)
{
	this->fatal(msg.str(), file, line);
}


void GameLogger::crash(std::string msg, std::string file, int line)
{
	// Farbe: Rot
	this->setConsoleColor(RED);
	std::stringstream time;
	std::stringstream s;
	this->getCurrentTime(time);

	s << time.str() << ": [CRASH] In file \"" << file << "\" at line \'" << line << "\': " << std::endl
	  << time.str() << ": [CRASH] " << msg << std::endl;
	std::cout << s.str();

	s.str("");

	s << "[CRASH] In file \"" << file << "\" at \'" << line << "\': " << std::endl
		<< "[CRASH] " << msg << std::endl;

	MessageBoxA(NULL, s.str().c_str(), "Crash", MB_ICONERROR | MB_OK);
	exit(0);
}

void GameLogger::crash(std::stringstream& msg, std::string file, int line)
{
	this->crash(msg.str(), file, line);
}

void GameLogger::debug(std::string msg)
{
	if (this->m_bdebug)
	{
		// Farbe:Blau
		this->setConsoleColor(BLUE);
		std::stringstream s;
		this->getCurrentTime(s);

		s << ": [DEBUG] " << msg << std::endl;
		std::cout << s.str();
	}
}

void GameLogger::debug(std::stringstream& msg)
{
	this->debug(msg.str());
}

void GameLogger::setDebug(bool debug)
{
	this->m_bdebug = debug;
}

void GameLogger::getCurrentTime(std::stringstream& dest)
{
	GetLocalTime(this->m_time);
	dest << "[" << ((this->m_time->wDay < 10) ? "0" : "") << this->m_time->wDay << "." 
		 << ((this->m_time->wMonth < 10) ? "0" : "") << this->m_time->wMonth << "." 
		 << ((this->m_time->wYear < 10) ? "0" : "") << this->m_time->wYear << "]["
		 << ((this->m_time->wHour < 10) ? "0" : "") << this->m_time->wHour << ":"
		 << ((this->m_time->wMinute < 10) ? "0" : "") << this->m_time->wMinute << ":"
		 << ((this->m_time->wSecond < 10) ? "0" : "") << this->m_time->wSecond << "]";
}