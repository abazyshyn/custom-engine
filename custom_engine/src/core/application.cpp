#include "pch.hpp"

#include "application.hpp" // target

#include "src/core/window.hpp"

#include <glad/glad.h>

namespace Engine
{

    void CApplication::Run()
    {
        for (; m_Window.m_IsRunning;)
        {
            m_Window.OnUpdate();
        }
    }

    CApplication::CApplication()
        : m_Window(CWindow::GetInstance())
    {
    }

} // namespace Engine
