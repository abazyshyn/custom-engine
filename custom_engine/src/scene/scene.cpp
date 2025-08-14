#include "pch.hpp"

#include "scene.hpp" // target

#include "src/core/window.hpp"
#include "src/renderer/camera.hpp"
#include "src/renderer/editor_camera.hpp"
#include "src/scene/entity.hpp"
#include "src/data/constants.hpp"

namespace Engine
{

    CScene::CScene()
        : m_Window(CWindow::GetInstance()),
          m_DebugNormalShader(std::make_unique<CShader>(
              std::vector<std::filesystem::path>{Constants::ENGINE_BASE_SHADERS_PATH + "gl_debug_normal.vert",
                                                 Constants::ENGINE_BASE_SHADERS_PATH + "gl_debug_normal.geom",
                                                 Constants::ENGINE_BASE_SHADERS_PATH + "gl_debug_normal.frag"}))
    {
    }

    void CScene::DrawDebugNormals(const glm::mat4 &ct_ModelMatrix, const glm::mat4 &ct_ViewMatrix,
                                  const std::shared_ptr<CEditorCamera> &ct_pEditorCamera, const std::shared_ptr<CEntity> &ct_pEntity)
    {
        m_DebugNormalShader->Bind();
        m_DebugNormalShader->SetUniformMatrix4fv("u_ModelMatrix", ct_ModelMatrix);
        m_DebugNormalShader->SetUniformMatrix4fv("u_ViewMatrix", ct_ViewMatrix);
        m_DebugNormalShader->SetUniformMatrix4fv("u_ProjectionMatrix", ct_pEditorCamera->CalculatePerspectiveProjectionMatrix(m_Window));
        ct_pEntity->Draw(*m_DebugNormalShader);
    }

} // namespace Engine
