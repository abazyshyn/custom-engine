#pragma once

#include "platform/windows/macro.hpp"
#include "src/renderer/shader.hpp"

namespace Engine
{
    // Forward declaration
    class CWindow;
    class CEditorCamera;
    class CEntity;
    // class CSkybox;

    class ENGINE_API CScene
    {
    public:
        CScene();
        virtual ~CScene() = default;

        /**
         * @brief Updates a scene
         *
         * @param[in] t_DeltaTime Time taken to render last frame
         */
        virtual void OnUpdate(const float ct_DeltaTime) = 0;

    protected:
        CWindow &m_Window;
        std::unique_ptr<CShader> m_DebugNormalShader;
        // CSkybox &m_Skybox;

        void DrawDebugNormals(const glm::mat4 &ct_ModelMatrix, const glm::mat4 &ct_ViewMatrix,
                              const std::shared_ptr<CEditorCamera> &ct_pEditorCamera, const std::shared_ptr<CEntity> &ct_pEntity);

    private:
        virtual void Init() = 0;
    };

} // namespace Engine
