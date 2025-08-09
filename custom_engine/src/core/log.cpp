#include "pch.hpp"

#include "log.hpp" // target

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Engine
{

    std::shared_ptr<spdlog::logger> CLog::s_EngineLogger;
    std::shared_ptr<spdlog::logger> CLog::s_ClientLogger;

    void CLog::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        s_EngineLogger = spdlog::stdout_color_mt("ENGINE");
        s_EngineLogger->set_level(spdlog::level::level_enum::trace);

        s_ClientLogger = spdlog::stdout_color_mt("CLIENT");
        s_ClientLogger->set_level(spdlog::level::level_enum::trace);
    }

} // namespace Engine
