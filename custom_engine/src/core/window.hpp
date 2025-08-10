#pragma once

#include "src/lib/glfw.hpp"
#include "src/utils/singleton.hpp"
#include "platform/windows/macro.hpp"

namespace Engine
{

    /**
     * @brief Implementation of the platform specific window
     * using GLFW library
     *
     * Implemented using Mayers' Singleton pattern
     * Neither CopyConstructible/MoveConstructible nor
     * CopyAssignable/MoveAssignable
     */
    class ENGINE_API CWindow final : public Utils::CSingleton<CWindow>
    {
    public:
        friend class Utils::CSingleton<CWindow>;

        /**
         * @brief Indicates status of the main loop
         */
        bool m_IsRunning;

        ~CWindow();

        /**
         * @brief Updates window
         */
        void OnUpdate();

        /**
         * @brief Returns pointer to window
         *
         * @return Pointer to window
         */
        [[nodiscard]] GLFWwindow *GetWindowPointer() const { return m_GlfwData.m_pWindow; }
        /**
         * @brief Returns window width
         *
         * @return Window width
         */
        [[nodiscard]] int32_t GetWidth() const { return m_GlfwData.m_WindowWidth; }
        /**
         * @brief Returns window height
         *
         * @return Window height
         */
        [[nodiscard]] int32_t GetHeight() const { return m_GlfwData.m_WindowHeight; }

    private:
        unsigned char _pad[7] = {}; // Explicit padding

        GLFW::GlfwData_s m_GlfwData;

        CWindow();

        void Init();
        void Shutdown() const;
    };

} // namespace Engine
