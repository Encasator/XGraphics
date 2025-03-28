#include "ilogger.h"

std::unordered_map<LogLevel, std::string> modeMap
{
	{DEBUG, " DEBUG "},
	{INFO, " INFO "},
	{WARNING, " WARNING "},
	{ERR, " ERR "},
	{FATAL, " FATAL "},
	{CRITICAL, " CRITICAL "}
};