#include "pch.hpp"

#include "application.hpp" // target

#include "assert.hpp"

namespace Engine
{

    void CApplication::Run()
    {
        for (;;)
        {
            ENGINE_INFO_LOG("Engine is running");
        }
    }

} // namespace Engine
