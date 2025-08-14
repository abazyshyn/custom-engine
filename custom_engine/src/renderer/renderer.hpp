#pragma once

#include "src/utils/singleton.hpp"
// #include "platform/windows/macro.hpp" TODO

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
    class CRenderer final : public Utils::CSingleton<CRenderer>
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

    private:
        CRenderer();
    };

} // namespace Engine
