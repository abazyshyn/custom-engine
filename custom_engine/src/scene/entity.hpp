#pragma once

#include "platform/windows/macro.hpp"
#include "src/renderer/model.hpp"

namespace Engine
{
    // Forward declaration
    class CModel;
    class CShader;

    /**
     * @brief Implementation of a base class "scene entity"
     *
     * Provides common interface for all entities in a scene
     */
    class ENGINE_API CEntity
    {
    public:
        explicit CEntity(const CModel &ct_Model);

        virtual ~CEntity() = default;

        /**
         * @brief Draws a scene entity
         *
         * @param[in] ct_Shader Shader
         */
        virtual void Draw(CShader &ct_Shader) const;

    private:
        CModel m_Model;
    };

} // namespace Engine
