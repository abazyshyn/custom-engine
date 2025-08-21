#include "pch.hpp"

#include "renderer.hpp" // target

#include "src/core/window.hpp"
#include "src/scene/scene.hpp"
#include "src/lib/opengl.hpp"
#include <glad/glad.h>

namespace Engine
{

    void CRenderer::OnRender(const float ct_DeltaTime)
    {
        for (const auto &scene : m_Scenes)
        {
            scene->OnUpdate(ct_DeltaTime);
        }
    }

    CRenderer::CRenderer()
    {
        OPENGL_ENABLE_DEBUG;
    }

} // namespace Engine
