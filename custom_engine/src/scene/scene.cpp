#include "pch.hpp"

#include "scene.hpp" // target

#include "src/core/window.hpp"

namespace Engine
{

    CScene::CScene()
        : m_Window(CWindow::GetInstance())
    {
    }

} // namespace Engine
