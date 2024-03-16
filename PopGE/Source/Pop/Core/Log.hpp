#pragma once

#include <filesystem>
#include <fstream>
#include <string>

#include "Core.hpp"
#include "LogLevel.hpp"

namespace Pop::Core
{
	class POP_API Log
	{
		// Attributes
	private:
		static std::ofstream logFile;

		// Methods
	public:
		static void OpenFile(const std::filesystem::path& p_filename);
		static void CloseFile();

		static void Print(const std::string& p_log, const LogLevel& p_logLevel);
	};

	void POP_API DebugLog(const std::string& p_filename, const unsigned int p_line, const std::string& p_functionName, const std::string p_log, const LogLevel& p_logLevel);
}

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define LOG(p_log, p_logLevel) Pop::Core::DebugLog(__FILENAME__, __LINE__, __func__, p_log, p_logLevel);

#ifdef POP_DEBUG
	#define Assertion(p_expression, p_log) if(!(p_expression)) { LOG(p_log, LogLevel::Critical); __debugbreak(); }
#else
	#define Assertion(p_expression, p_log) if(!(p_expression)) { LOG(p_log, LogLevel::Critical); abort(); }
#endif