#include "pch.hpp"

#include "entity.hpp" // target

#include "src/renderer/shader.hpp"

namespace Engine
{

    CEntity::CEntity(const CModel &ct_Model)
        : m_Model(ct_Model)
    {
    }

    void CEntity::Draw(CShader &ct_Shader) const
    {
        m_Model.Draw(ct_Shader);
    }

} // namespace Engine
