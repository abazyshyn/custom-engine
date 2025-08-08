#pragma once

// #include "src/utils/singleton.hpp"
#include "platform/windows/macro.hpp"

#include <spdlog/spdlog.h>

namespace Engine
{

    class ENGINE_API CLog
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetEngineLogger() { return s_EngineLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_EngineLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

} // namespace Engine
