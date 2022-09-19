#pragma once

#include <stdio.h>

namespace Gfx
{
	enum LogPriority
	{
		Trace, Debug, Info, Warn, Error, Fatal
	};

	class Log
	{
	public:
		static void SetPriority(LogPriority priority) { Log::m_priority = priority; }

		template<typename... Args>
		static void Trace(const char* message, Args... args)
		{
			if (m_priority <= LogPriority::Trace)
			{
				printf("[Trace] \t%s %s\n", message, args...);
			}
		}


		template<typename... Args>
		static void Debug(const char* message, Args... args)
		{
			if (m_priority <= LogPriority::Debug)
			{
				printf("[Debug] \t%s %s\n", message, args...);
			}
		}


		template<typename... Args>
		static void Info(const char* message, Args... args)
		{
			if (m_priority <= LogPriority::Info)
			{
				printf("[Info] \t%s %s\n", message, args...);
			}
		}


		template<typename... Args>
		static void Warn(const char* message, Args... args)
		{
			if (m_priority <= LogPriority::Warn)
			{
				printf("[Warn] \t%s %s\n", message, args...);
			}
		}


		template<typename... Args>
		static void Error(const char* message, Args... args)
		{
			if (m_priority <= LogPriority::Error)
			{
				printf("[Error] \t%s %s\n", message, args...);
			}
		}


		template<typename... Args>
		static void Fatal(const char* message, Args... args)
		{
			if (m_priority <= LogPriority::Fatal)
			{
				printf("[Fatal] \t%s %s\n", message, args...);
			}
		}

	private:
		static LogPriority m_priority;
	};

}


