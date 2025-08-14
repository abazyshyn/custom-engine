#include "pch.hpp"

#include "renderer.hpp" // target

#include "src/core/window.hpp"
#include "src/scene/scene.hpp"
#include "src/lib/opengl.hpp"
#include <glad/glad.h>

namespace Engine
{

    void CRenderer::OnRender(const float ct_DeltaTime, const std::shared_ptr<CScene> &ct_pScene)
    {
        ct_pScene->OnUpdate(ct_DeltaTime);
    }

    void CRenderer::OnRender(const float ct_DeltaTime, const std::vector<std::shared_ptr<CScene>> &ct_Scenes)
    {
        for (const std::shared_ptr<CScene> &pScene : ct_Scenes)
        {
            OnRender(ct_DeltaTime, pScene);
        }
    }

    CRenderer::CRenderer()
    {
        OPENGL_ENABLE_DEBUG;
    }

} // namespace Engine
