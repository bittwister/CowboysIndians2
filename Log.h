#pragma once
#include <iostream>
#include <string>
#include <ctime>

class Log
{
public:
	enum Level { Error = 0, Warning, Info };

private:
	Level m_Log_Level;

public:
	Log();
	Log(Level);
	void SetLogLevel(Level);
	void LogMessage(Level, const char*);

private:
	void PrintError(const char*);
	void PrintWarning(const char*);
	void PrintInfo(const char*);
};

