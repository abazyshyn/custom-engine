#include <cengine.hpp>                     // should be custom_engine
#include <src/core/engine_entry_point.hpp> // fix path "should be custom_engine/src/core/..."
#include "basic_light_scene/basic_light_scene.hpp"

class CSandbox final : public Engine::CApplication
{
};

Engine::CApplication &Engine::CreateApplication()
{
    // issue with transferring the ownership
    CSandbox::PushScenesToRenderer(std::make_shared<Sandbox::CBasicLightScene>());

    return CSandbox::GetInstance();
}
