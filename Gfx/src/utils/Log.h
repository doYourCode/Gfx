#pragma once

#include <memory>

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Gfx
{
	
	class Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define LOG_CORE_TRACE(...)    ::Gfx::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...)     ::Gfx::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)     ::Gfx::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...)    ::Gfx::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_CRITICAL(...) ::Gfx::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define LOG_TRACE(...)         ::Gfx::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)          ::Gfx::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)          ::Gfx::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)         ::Gfx::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)      ::Gfx::Log::GetClientLogger()->critical(__VA_ARGS__)

