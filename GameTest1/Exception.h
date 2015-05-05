#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

extern void PrintException(std::string, int, std::string, std::string);

#define EXCEPTION(msg) PrintException(msg, __LINE__, __FILE__, __FUNCTION__)


#endif