#pragma once

#include "platform/windows/macro.hpp"

namespace Engine
{
    // Forward declaration
    class CWindow;
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
        virtual void OnUpdate(float t_DeltaTime) = 0;

    protected:
        CWindow &m_Window;
        // CSkybox &m_Skybox;
    };

} // namespace Engine
