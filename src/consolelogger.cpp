#include <iostream>
#include <sstream>

#include "consolelogger.h"
#include "format.hpp"

auto ConsoleLogger::getCurrentTime() const -> std::chrono::system_clock::time_point
{
	return std::chrono::system_clock::now();
}

auto ConsoleLogger::getTextTime() -> std::string
{
	auto currentTime = getCurrentTime();

	std::time_t nTime = std::chrono::system_clock::to_time_t(currentTime);
	std::tm localTime;
	localtime_s(&localTime, &nTime);

	char timeFormatString[30];

	strftime(timeFormatString, sizeof(timeFormatString), "%H:%M:%S", &localTime);

	std::ostringstream ss;
	ss << timeFormatString;

	return ss.str();
}

void ConsoleLogger::log(LogLevel mode, std::string text)
{
	std::cout << getTextTime() << modeMap[mode] << text << std::endl;
}
