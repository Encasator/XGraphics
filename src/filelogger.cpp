#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

#include "filelogger.h"

auto FileLogger::getCurrentTime() const -> std::chrono::system_clock::time_point 
{
	return std::chrono::system_clock::now();
}

auto FileLogger::getTextTime() -> std::string 
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

FileLogger::FileLogger(std::string logFileName)
{
	if (LogFile.is_open()) LogFile.close();

	LogFile.open(logFileName, std::ios::app);
	if (!LogFile.is_open())
	{
		std::cerr << "Failed to open log file: " << logFileName << std::endl;
	}

	LogFile << "Logging start point" << std::endl;
	LogFile << "------------------------------------------------------------------------------" << std::endl;
}

FileLogger::~FileLogger() 
{
	if (!LogFile.is_open()) 
	{
		std::cerr << "File is not opened" << std::endl;
		return;
	}

	LogFile << "------------------------------------------------------------------------------" << std::endl;
	LogFile << "Logging end point" << std::endl;
	LogFile.close();
}

void FileLogger::log(LogLevel mode, std::string text)
{
	LogFile << getTextTime() << modeMap[mode] << text << std::endl;
}



