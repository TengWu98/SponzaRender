#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

SPONZA_RENDER_NAMESPACE_BEGIN
	class Logger : public Singleton<Logger> {
	public:
		static std::shared_ptr<spdlog::logger> GetLogger();
	private:
		Logger() = delete;
		Logger(const Logger&) = delete;
		Logger& operator=(const Logger&) = delete;
	private:
		static std::shared_ptr<spdlog::logger> m_spLogger;
	};

SPONZA_RENDER_NAMESPACE_END

// Error
#define LOG_DEV_ERROR(...) ::SponzaRender::Logger::GetLogger()->error(__VA_ARGS__)
// Warning
#define LOG_DEV_WARN(...) ::SponzaRender::Logger::GetLogger()->warn(__VA_ARGS__)
// Info
#define LOG_DEV_INFO(...) ::SponzaRender::Logger::GetLogger()->info(__VA_ARGS__)
// Trace
#define LOG_DEV_TRACE(...) ::SponzaRender::Logger::GetLogger()->trace(__VA_ARGS__)
