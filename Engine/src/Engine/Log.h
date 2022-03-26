#pragma once

#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Core.h"

namespace Toy
{
	class TOY_API Log
	{
	public:
		Log();
		virtual ~Log();

		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_coreLogger;
		}

		static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_clientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};
}

#define TOY_CORE_LOG_TRACE(...)				::Toy::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TOY_CORE_LOG_WARN(...)				::Toy::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TOY_CORE_LOG_ERROR(...)				::Toy::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TOY_CORE_LOG_FATAL(...)				::Toy::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define TOY_CLIENT_LOG_TRACE(...)			::Toy::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TOY_CLIENT_LOG_WARN(...)			::Toy::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TOY_CLIENT_LOG_ERROR(...)			::Toy::Log::GetClientLogger()->error(__VA_ARGS__)
#define TOY_CLIENT_LOG_FATAL(...)			::Toy::Log::GetClientLogger()->fatal(__VA_ARGS__)