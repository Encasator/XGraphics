#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <fstream>
#include <chrono>

#include "ilogger.h"

class FileLogger final : public ILogger
{
private:
	std::ofstream LogFile;

	auto getCurrentTime() const -> std::chrono::system_clock::time_point;
	auto getTextTime() -> std::string;
public:
	FileLogger() = default;
	FileLogger(std::string logFileName);
	FileLogger(const FileLogger& other) = delete;
	FileLogger(FileLogger&&) = delete;
	~FileLogger() override;

	void log(LogLevel mode, std::string text) override;
};


#endif //FILELOGGER_H