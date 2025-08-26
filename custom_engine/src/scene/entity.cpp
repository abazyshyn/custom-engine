#include "pch.hpp"

#include "entity.hpp" // target

#include "src/renderer/shader.hpp"

namespace Engine
{

    CEntity::CEntity(CModel &&t_Model)
        : m_Model(std::move(t_Model))
    {
    }

    void CEntity::Draw(CShader &ct_Shader) const
    {
        m_Model.Draw(ct_Shader);
    }

} // namespace Engine
