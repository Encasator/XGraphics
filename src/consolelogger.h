#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include <chrono>

#include "ilogger.h"

class ConsoleLogger final : public ILogger
{
private:
	auto getCurrentTime() const->std::chrono::system_clock::time_point;
	auto getTextTime() -> std::string;
public:
	ConsoleLogger() = default;
	ConsoleLogger(const ConsoleLogger& other) = delete;
	ConsoleLogger(ConsoleLogger&&) = delete;
	~ConsoleLogger() override = default;

	void log(LogLevel mode, std::string text) override;
};

#endif //CONSOLELOGGER_H