#pragma once

namespace Sandbox
{

    // TODO: write docs
    class CBasicLightScene final : public Engine::CScene
    {
    public:
        friend Engine::CScene;

        void OnUpdate(float t_DeltaTime) override;
    };

} // namespace Sandbox
