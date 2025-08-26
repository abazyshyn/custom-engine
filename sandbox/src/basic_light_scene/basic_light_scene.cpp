#include <pch.hpp>
#include <cengine.hpp>

#include "basic_light_scene.hpp" // target

#include "sponza_entity.hpp"
#include "data/constants.hpp"

namespace Sandbox
{

    CBasicLightScene::CBasicLightScene()
        : m_pFlyCamera(std::make_shared<Engine::CFlyCamera>()),
          m_pBasicShader(std::make_unique<Engine::CShader>(
              std::vector<std::filesystem::path>{Constants::SANDBOX_BASE_SHADERS_PATH + "gl_scene.vert",
                                                 Constants::SANDBOX_BASE_SHADERS_PATH + "gl_basic.frag"})),
          m_pBasicLightingShader(std::make_unique<Engine::CShader>(
              std::vector<std::filesystem::path>{Constants::SANDBOX_BASE_SHADERS_PATH + "gl_basic_lighting.vert",
                                                 Constants::SANDBOX_BASE_SHADERS_PATH + "gl_basic_lighting.frag"}))
    {
        m_Entities.emplace_back(std::make_unique<CSponzaEntity>());
        Init();
    }

    void CBasicLightScene::OnUpdate(const float ct_DeltaTime)
    {
        // Update camera movement
        m_pFlyCamera->CameraKeyboardInput(m_Window.GetWindowPointer(), ct_DeltaTime);
        m_pFlyCamera->CameraMouseMovementInput(m_Window.GetWindowPointer());

        // Set view matrix to the uniform block
        const glm::mat4 viewMatrix = m_pFlyCamera->CalculateViewMatrix();

        m_UBO.Bind();
        m_UBO.SetData(sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(viewMatrix));
        m_UBO.UnBind();

        // Lighting ====================================================================
        m_pBasicShader->Bind();

        glm::vec3 lightPosition = glm::vec3(glm::sin(glfwGetTime()) * 2.0f, 0.3f, 0.0f);

        // for (const std::shared_ptr<Engine::CEntity> &pEntity : m_LightCastEntities)
        //{
        //     glm::mat4 modelMatrix(1.0f);
        //     modelMatrix = glm::translate(modelMatrix, lightPosition);
        //     modelMatrix = glm::scale(modelMatrix, glm::vec3(0.05f));

        //    m_pBasicShader->SetUniformMatrix4fv("u_ModelMatrix", modelMatrix);

        //    pEntity->Draw(*m_pBasicShader);

        //    this->DrawDebugNormals(modelMatrix, viewMatrix, m_pFlyCamera, pEntity);
        //}

        m_pBasicLightingShader->Bind();

        for (const std::unique_ptr<Engine::CEntity> &pEntity : m_Entities)
        {
            glm::mat4 modelMatrix(1.0f);
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.002f));

            glm::mat3 normalMatrix = glm::transpose(glm::inverse(viewMatrix * modelMatrix));

            m_pBasicLightingShader->SetUniform3fv("u_DirectionalLight.m_Position", glm::vec3(glm::vec4(lightPosition, 1.0f) * viewMatrix));

            m_pBasicLightingShader->SetUniformMatrix3fv("u_NormalMatrix", normalMatrix);
            m_pBasicLightingShader->SetUniformMatrix4fv("u_ModelMatrix", modelMatrix);

            pEntity->Draw(*m_pBasicLightingShader);

            this->DrawDebugNormals(modelMatrix, viewMatrix, m_pFlyCamera, pEntity);
        }
        // ================================================================================
    }

    void CBasicLightScene::Init()
    {
        m_pFlyCamera->SetLastPosX(static_cast<float>(this->m_Window.GetWidth()) / 2.0f);
        m_pFlyCamera->SetLastPosY(static_cast<float>(this->m_Window.GetHeight()) / 2.0f);

        m_UBO.SetupUBO(2 * sizeof(glm::mat4));
        m_UBO.BindRange(0, 0, 2 * sizeof(glm::mat4));

        // Set projection matrix to the uniform block
        const glm::mat4 projectionMatrix = m_pFlyCamera->CalculatePerspectiveProjectionMatrix(this->m_Window);
        m_UBO.Bind();
        m_UBO.SetData(0, sizeof(glm::mat4), glm::value_ptr(projectionMatrix));
        m_UBO.UnBind();
    }

    void CBasicLightScene::SetupLight()
    {
        m_pBasicLightingShader->Bind();

        // Populate u_DirectionalLight struct
        // TODO: color can be changed in the future
        m_pBasicLightingShader->SetUniform3fv("u_DirectionalLight.m_DiffuseColor", glm::vec3(0.4f, 0.4f, 0.4f));
        m_pBasicLightingShader->SetUniform3fv("u_DirectionalLight.m_SpecularColor", glm::vec3(1.0f, 1.0f, 1.0f));
    }

} // namespace Sandbox
