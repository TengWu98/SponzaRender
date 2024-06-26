#include "pch.h"
#include "Logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

SPONZA_RENDER_NAMESPACE_BEGIN

std::shared_ptr<spdlog::logger> Logger::m_spLogger = nullptr;

std::shared_ptr<spdlog::logger> Logger::GetLogger()
{
	if (!m_spLogger)
	{
		std::vector<spdlog::sink_ptr> logSinks;
		logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("SponzaRender.log", true));

		logSinks[0]->set_pattern("%^[%T] %n: %v%$");
		logSinks[1]->set_pattern("[%T] [%l] %n: %v");

		m_spLogger = std::make_shared<spdlog::logger>("SponzaRender", begin(logSinks), end(logSinks));
		spdlog::register_logger(m_spLogger);
		m_spLogger->set_level(spdlog::level::trace);
		m_spLogger->flush_on(spdlog::level::trace);
	}

	return m_spLogger;
}

SPONZA_RENDER_NAMESPACE_END