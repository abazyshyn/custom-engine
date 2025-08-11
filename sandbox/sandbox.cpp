#include <cengine.hpp>                     // should be custom_engine
#include <src/core/engine_entry_point.hpp> // fix path "should be custom_engine/src/core/..."

class CSandbox final : public Engine::CApplication
{
    // TODO: commit function that sends all scenes to renderer
};

Engine::CApplication &Engine::CreateApplication()
{
    return CSandbox::GetInstance();
}
