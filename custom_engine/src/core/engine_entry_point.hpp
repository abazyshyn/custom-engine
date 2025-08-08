#pragma once

#include <cstdlib>

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
