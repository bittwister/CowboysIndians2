#include "Log.h"

Log::Log()
{
}

void Log::SetLogLevel(Level level)
{
}

void Log::LogMessage(Level level, const char* message)
{
	switch (level) {
	case Log::Error:
		Log::PrintError(message);
		break;
	case Log::Warning:
		Log::PrintWarning(message);
		break;
	case Log::Info:
		Log::PrintInfo(message);
		break;
	}
}

void Log::PrintError(const char* message)
{
	if (Log::m_Log_Level >= Log::Error)	{
		std::cout << "[ERROR] " << std::endl;
	}
}

void Log::PrintWarning(const char * message)
{
	if (Log::m_Log_Level >= Log::Warning) {
		std::cout << "[WARNING] " << std::endl;
	}
}

void Log::PrintInfo(const char * message)
{
	if (Log::m_Log_Level >= Log::Info) {
		std::cout << "[INFO] " << std::endl;
	}
}

