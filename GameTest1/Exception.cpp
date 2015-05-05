#include <string>
#include <sstream>
#include <iostream>
#include <Windows.h>
#include "Exception.h"

void PrintException(std::string msg, int line, std::string file, std::string function)
{
	std::stringstream ss;

	ss << std::endl;
	ss << "=================================" << std::endl;
	ss << "  An Exception occurred: " << msg << std::endl;
	ss << "  File: "<< file << std::endl;
	ss << "  Line: " << line << std::endl;
	ss << "  Function: " << function << std::endl;
	ss << "=================================" << std::endl;

	std::cout << ss.str().c_str();

	MessageBox(NULL, ss.str().c_str(), "Exception", MB_OK | MB_ICONERROR);

	exit(0);
}