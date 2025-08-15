#pragma once

#include "src/utils/singleton.hpp"
#include "platform/windows/macro.hpp"

namespace Engine
{
    class CScene;
    class CWindow;
    class CRenderer;

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

        // TODO: docs
        static void PushScenesToRenderer(const std::shared_ptr<CScene> &ct_pScene);

        // TODO: docs
        static void PushScenesToRenderer(const std::vector<std::shared_ptr<CScene>> &ct_Scenes);

    private:
        CWindow &m_Window;
        CRenderer &m_Renderer;
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
