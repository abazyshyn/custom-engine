#include "pch.hpp"

#include "application.hpp" // target

#include "src/core/window.hpp"
#include "src/renderer/renderer.hpp"
#include <glad/glad.h>

namespace Engine
{

    void CApplication::Run()
    {
        while (m_Window.m_IsRunning)
        {
            const float deltaTime = CalculateDeltaTime();

            m_Window.OnUpdate();
        }
    }

    CApplication::CApplication()
        : m_Window(CWindow::GetInstance()),
          m_Renderer(CRenderer::GetInstance()),
          m_LastFrameTime(0.0f)
    {
    }

    float CApplication::CalculateDeltaTime()
    {
        const float currentFrameTime = static_cast<float>(glfwGetTime());
        const float deltaTime = currentFrameTime - m_LastFrameTime;
        m_LastFrameTime = currentFrameTime;

        return deltaTime;
    }

} // namespace Engine
