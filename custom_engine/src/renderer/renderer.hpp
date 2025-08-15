#pragma once

#include "src/utils/singleton.hpp"
#include "platform/windows/macro.hpp"

namespace Engine
{

    // Forward declaration
    class CScene;

    /**
     * @brief Implementation of the main renderer
     *
     * Implemented using Mayers' Singleton pattern
     *
     * Neither CopyConstructible/MoveConstructible nor
     * CopyAssignable/MoveAssignable
     */
    class ENGINE_API CRenderer final : public Utils::CSingleton<CRenderer>
    {
    public:
        friend class Utils::CSingleton<CRenderer>;

        /**
         * @brief Main renderer, renders and manages single scene
         *
         * @param[in] t_DeltaTime Delta time
         */
        void OnRender(const float ct_DeltaTime, const std::shared_ptr<CScene> &ct_pScene);

        /**
         * @brief Main renderer, renders and manages all scenes
         *
         * @param[in] t_DeltaTime Delta time
         */
        void OnRender(const float ct_DeltaTime, const std::vector<std::shared_ptr<CScene>> &ct_Scenes);

        void SetScenes(const std::shared_ptr<CScene> &ct_pScene) { m_Scenes.emplace_back(ct_pScene); }

        void SetScenes(const std::vector<std::shared_ptr<CScene>> &ct_Scenes) { m_Scenes.insert(m_Scenes.end(), ct_Scenes.begin(), ct_Scenes.end()); }

    private:
        std::vector<std::shared_ptr<CScene>> m_Scenes;

        CRenderer();
    };

} // namespace Engine
