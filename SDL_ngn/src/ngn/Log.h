#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace ngn
{
	class NGN_API Log
	{
	public:
		Log();
		~Log();
		
		static void Init();

		inline static std::shared_ptr<spdlog::logger> & GetCoreLogger() { return s_coreLogger; }
		inline static std::shared_ptr<spdlog::logger> & GetAppLogger() { return s_appLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_appLogger;
	};
}

#define NGN_CORE_TRACE(...) ::ngn::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NGN_CORE_INFO(...)	::ngn::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NGN_CORE_WARN(...)	::ngn::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NGN_CORE_FATAL(...) ::ngn::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define NGN_CORE_ERROR(...) ::ngn::Log::GetCoreLogger()->error(__VA_ARGS__)

#define NGN_TRACE(...)		::ngn::Log::GetAppLogger()->trace(__VA_ARGS__)
#define NGN_INFO(...)		::ngn::Log::GetAppLogger()->info(__VA_ARGS__)
#define NGN_WARN(...)		::ngn::Log::GetAppLogger()->warn(__VA_ARGS__)
#define NGN_ERROR(...)		::ngn::Log::GetAppLogger()->error(__VA_ARGS__)
#define NGN_FATAL(...)		::ngn::Log::GetAppLogger()->fatal(__VA_ARGS__)
