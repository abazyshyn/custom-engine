#include "pch.hpp"

#include "application.hpp" // target

#include "assert.hpp"

namespace Engine
{

    void CApplication::Run()
    {
        ENGINE_ASSERT(0);

        for (;;)
        {
            std::cout << "Engine is running" << std::endl;
        }
    }

} // namespace Engine
