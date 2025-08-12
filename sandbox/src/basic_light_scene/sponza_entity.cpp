#include <cengine.hpp>

#include "sponza_entity.hpp" // target

#include "data/constants.hpp"

namespace Sandbox
{

    CSponzaEntity::CSponzaEntity()
        : Engine::CEntity(Engine::CModel(Constants::SANDBOX_BASE_MODELS_PATH + "sponza/scene.gltf"))
    {
    }

} // namespace Sandbox
