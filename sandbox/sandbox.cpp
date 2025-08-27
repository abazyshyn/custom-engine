#include <cengine.hpp>                     // should be custom_engine
#include <src/core/engine_entry_point.hpp> // fix path "should be custom_engine/src/core/..."

class CSandbox final : public Engine::CApplication
{
};

Engine::CApplication &Engine::CreateApplication()
{
    return CSandbox::GetInstance();
}
