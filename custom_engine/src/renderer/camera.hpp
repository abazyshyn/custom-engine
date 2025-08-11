#pragma once

#include "platform/windows/macro.hpp"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace Engine
{

    // Forward declaration
    class CWindow;

    /**
     * @brief Implementation of the base camera class
     */
    class ENGINE_API CCamera
    {
    public:
        virtual ~CCamera() = default;

        // TODO: write docs
        virtual void CameraKeyboardInput(GLFWwindow *t_pWindow, float t_DeltaTime) = 0;
        // TODO: write docs
        virtual void CameraMouseMovementInput(GLFWwindow *t_pWindow) = 0;

        // TODO: write docs
        virtual [[nodiscard]] glm::mat4 CalculateViewMatrix() const = 0;
        // TODO: write docs
        virtual [[nodiscard]] glm::mat4 CalculatePerspectiveProjectionMatrix(const CWindow &ct_pWindow) const = 0;

        // TODO: write docs
        virtual [[nodiscard]] float GetFOV() const = 0;
        // TODO: write docs
        virtual [[nodiscard]] glm::vec3 GetCameraPos() const = 0;
        // TODO: write docs
        virtual [[nodiscard]] glm::vec3 GetCameraFront() const = 0;
        // TODO: write docs
        virtual [[nodiscard]] glm::vec3 GetCameraUp() const = 0;
    };

} // namespace Engine
