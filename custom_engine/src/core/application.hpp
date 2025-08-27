#pragma once

#include "src/utils/singleton.hpp"
#include "platform/windows/macro.hpp"

namespace Engine
{
    class CScene;
    class CWindow;

    /**
     * @brief Implementation of the application
     *
     * Implemented using Mayers' Singleton pattern
     *
     * Neither CopyConstructible/MoveConstructible nor
     * CopyAssignable/MoveAssignable
     *
     * Controls whole application
     */
    class ENGINE_API CApplication : public Utils::CSingleton<CApplication>
    {
    public:
        friend Utils::CSingleton<CApplication>;

        /**
         * @brief Main loop
         */
        void Run();

    private:
        CWindow &m_Window;
        float m_LastFrameTime;
        unsigned char _pad[4] = {}; // Explicit padding

        CApplication();

        float CalculateDeltaTime();
    };

    /**
     * @brief Returns instance of the application
     *
     * Must be implemented on the client side
     */
    CApplication &CreateApplication();

} // namespace Engine
