#include <cengine.hpp>

class CSandbox final : public Engine::CApplication
{
public:
};

Engine::CApplication &Engine::CreateApplication()
{
    return CSandbox::GetInstance();
}
