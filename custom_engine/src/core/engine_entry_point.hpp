#pragma once

#include <cstdlib>

#if defined(ENGINE_WINDOWS)

extern Engine::CApplication &Engine::CreateApplication();

/**
 * @brief Program's entry point
 */
int main(int argc, char **argv)
{
    Engine::CLog::Init();
    Engine::CLog::GetEngineLogger()->warn("Engine started.");
    Engine::CLog::GetClientLogger()->info("Client started.");

    Engine::CApplication &app = Engine::CreateApplication();

    // app.Run();

    return EXIT_SUCCESS;
}

#endif
