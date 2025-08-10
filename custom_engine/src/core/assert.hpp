#pragma once

#if defined(ENGINE_DEBUG) || defined(ENGINE_DEVELOPMENT)

#include "log.hpp"
#include <filesystem>

#if defined(ENGINE_LINUX)

#include <csignal>

/**
 * @brief Macro for braking on a line where assertion fails
 */
#define DEBUG_BREAK raise(SIGTRAP)

#elif defined(ENGINE_WINDOWS)

/**
 * @brief Macro for braking on a line where assertion fails
 */
#define DEBUG_BREAK __debugbreak()

#else // ENGINE_WINDOWS, ENGINE_LINUX

#error Custom Engine supports only Linux and Windows.

#endif // ENGINE_WINDOWS, ENGINE_LINUX

/**
 * @brief Custom assertion macro
 *
 * @param[in] expr Boolean expression
 */
#define ENGINE_ASSERT(expr)                                                                                                             \
    if (!expr)                                                                                                                          \
    {                                                                                                                                   \
        ENGINE_CRITICAL_LOG("Assertion '{0}' failed at {1}:{2}", #expr, std::filesystem::path(__FILE__).filename().string(), __LINE__); \
        DEBUG_BREAK;                                                                                                                    \
    }

#else // defined(LAB_DEBUG) || defined(LAB_DEVELOPMENT)

/**
 * @brief Macro that evaluates to nothing
 */
#define DEBUG_BREAK

/**
 * @brief Macro that evaluates to nothing
 */
#define LAB_ASSERT(expr)

#endif // defined(ENGINE_DEBUG) || defined(ENGINE_DEVELOPMENT)
