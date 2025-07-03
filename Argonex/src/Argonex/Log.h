#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

namespace Argonex
{
	class ARGONEX_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log

#define ARGONEX_CORE_TRACE(...)::Argonex::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ARGONEX_CORE_INFO(...)::Argonex::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ARGONEX_CORE_WARN(...)::Argonex::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ARGONEX_CORE_ERROR(...)::Argonex::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ARGONEX_CORE_FATAL(...)::Argonex::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log

#define ARGONEX_TRACE(...)::Argonex::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ARGONEX_INFO(...)::Argonex::Log::GetClientLogger()->info(__VA_ARGS__)
#define ARGONEX_WARN(...)::Argonex::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ARGONEX_ERROR(...)::Argonex::Log::GetClientLogger()->error(__VA_ARGS__)
#define ARGONEX_FATAL(...)::Argonex::Log::GetClientLogger()->fatal(__VA_ARGS__)