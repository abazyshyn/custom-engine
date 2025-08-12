#pragma once

namespace Sandbox
{

    // Forward declaration
    class Engine::CFlyCamera;
    class Engine::CShader;
    class Engine::CEntity;

    // TODO: write docs
    class CBasicLightScene final : public Engine::CScene
    {
    public:
        friend Engine::CScene;

        CBasicLightScene();

        void OnUpdate(float t_DeltaTime) override;

    private:
        Engine::CUniformBuffer m_UBO;

        std::unique_ptr<Engine::CFlyCamera> m_pFlyCamera;
        std::unique_ptr<Engine::CShader> m_pBasicShader; // TODO: temp
        std::unique_ptr<Engine::CShader> m_pBasicLightingShader;

        std::vector<std::shared_ptr<Engine::CEntity>> m_LightCastEntities;
        std::vector<std::shared_ptr<Engine::CEntity>> m_Entities;

        void Init() override;
        void SetupLight();
    };

} // namespace Sandbox
