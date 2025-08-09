#pragma once

#include "src/utils/singleton.hpp"
#include "platform/windows/macro.hpp"

#include <spdlog/spdlog.h>

namespace Engine
{

    /**
     * @brief Implementation of the logging system
     *
     * Implemented using Mayers' Singleton pattern
     *
     * Neither CopyConstructible/MoveConstructible nor
     * CopyAssignable/MoveAssignable
     */
    class ENGINE_API CLog final : public Utils::CSingleton<CLog>
    {
    public:
        friend Utils::CSingleton<CLog>;

        /**
         * @brief Initializes loggers for the engine and client side
         */
        static void Init();

        /**
         * @brief Returns engine logger
         *
         * @return Engine logger
         */
        inline static std::shared_ptr<spdlog::logger> &GetEngineLogger() { return s_EngineLogger; }
        /**
         * @brief Returns client logger
         *
         * @return Client logger
         */
        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_EngineLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

} // namespace Engine

#if defined(ENGINE_DEBUG) || defined(ENGINE_DEVELOPMENT)

#define ENGINE_TRACE_LOG(...) ::Engine::CLog::GetEngineLogger()->trace(__VA_ARGS__)
#define ENGINE_INFO_LOG(...) ::Engine::CLog::GetEngineLogger()->info(__VA_ARGS__)
#define ENGINE_WARN_LOG(...) ::Engine::CLog::GetEngineLogger()->warn(__VA_ARGS__)
#define ENGINE_ERROR_LOG(...) ::Engine::CLog::GetEngineLogger()->error(__VA_ARGS__)
#define ENGINE_CRITICAL_LOG(...) ::Engine::CLog::GetEngineLogger()->critical(__VA_ARGS__)

#define CLIENT_TRACE_LOG(...) ::Engine::CLog::GetClientLogger()->trace(__VA_ARGS__)
#define CLIENT_INFO_LOG(...) ::Engine::CLog::GetClientLogger()->info(__VA_ARGS__)
#define CLIENT_WARN_LOG(...) ::Engine::CLog::GetClientLogger()->warn(__VA_ARGS__)
#define CLIENT_ERROR_LOG(...) ::Engine::CLog::GetClientLogger()->error(__VA_ARGS__)
#define CLIENT_CRITICAL_LOG(...) ::Engine::CLog::GetClientLogger()->critical(__VA_ARGS__)

#else // defined(ENGINE_DEBUG) || defined(ENGINE_DEVELOPMENT)

#define ENGINE_TRACE_LOG(...)
#define ENGINE_INFO_LOG(...)
#define ENGINE_WARN_LOG(...)
#define ENGINE_ERROR_LOG(...)
#define ENGINE_CRITICAL_LOG(...)

#define CLIENT_TRACE_LOG(...)
#define CLIENT_INFO_LOG(...)
#define CLIENT_WARN_LOG(...)
#define CLIENT_ERROR_LOG(...)
#define CLIENT_CRITICAL_LOG(...)

#endif // defined(ENGINE_DEBUG) || defined(ENGINE_DEVELOPMENT)
