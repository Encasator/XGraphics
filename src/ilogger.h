#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <unordered_map>
#include <map>

enum LogLevel
{
	DEBUG,
	INFO,
	WARNING,
	ERR,
	FATAL,
	CRITICAL
};

extern std::unordered_map<LogLevel, std::string> modeMap;

class ILogger /// \brief Main Logger Interface
{
protected:
	ILogger() = default;
	ILogger(const ILogger&) = default;

	ILogger& operator=(const ILogger& other) = default;
public:
	virtual ~ILogger() = default;
	
	virtual void log(LogLevel mode, std::string text) = 0;
};

#endif //LOGGER_H