#include "pch.hpp"

#include "editor_camera.hpp" // target

#include "src/core/window.hpp"

namespace Engine
{

    CEditorCamera::CEditorCamera()
        : m_CameraPositionVector(0.0f, 0.0f, 0.0f),
          m_CameraFrontVector(0.0f, 0.0f, -1.0f),
          m_CameraUpVector(0.0f, 1.0f, 0.0f),
          m_CameraWorldUpVector(m_CameraUpVector),
          m_CameraRightVector(glm::normalize(glm::cross(m_CameraFrontVector, m_CameraUpVector))),
          m_FOV(45.0f),
          m_CursorPositionX(0.0f),
          m_CursorPositionY(0.0f),
          m_CursorLastPositionX(0.0f),
          m_CursorLastPositionY(0.0f),
          m_MouseSensitivity(0.3f),
          m_Pitch(0.0f),
          m_Yaw(-90.0f),
          m_Roll(0.0f),
          m_IsCursorPositionSet(false)
    {
        UpdateCameraVectors();
    }

    void CEditorCamera::CameraKeyboardInput(GLFWwindow *t_pWindow, const float ct_DeltaTime)
    {
        const float fCameraSpeed = 1.0f * ct_DeltaTime;

        if (glfwGetKey(t_pWindow, GLFW_KEY_W) == GLFW_PRESS)
        {
            m_CameraPositionVector += glm::normalize(m_CameraFrontVector) * fCameraSpeed;
            ENGINE_INFO_LOG("\nW key pressed.\nX: {0}\nY: {1}\nZ: {2}",
                            m_CameraPositionVector.x,
                            m_CameraPositionVector.y,
                            m_CameraPositionVector.z);
        }

        if (glfwGetKey(t_pWindow, GLFW_KEY_S) == GLFW_PRESS)
        {
            m_CameraPositionVector -= glm::normalize(m_CameraFrontVector) * fCameraSpeed;
            ENGINE_INFO_LOG("\nS key pressed.\nX: {0}\nY: {1}\nZ: {2}",
                            m_CameraPositionVector.x,
                            m_CameraPositionVector.y,
                            m_CameraPositionVector.z);
        }

        if (glfwGetKey(t_pWindow, GLFW_KEY_A) == GLFW_PRESS)
        {
            m_CameraPositionVector -= m_CameraRightVector * fCameraSpeed;
            ENGINE_INFO_LOG("\nA key pressed.\nX: {0}\nY: {1}\nZ: {2}",
                            m_CameraPositionVector.x,
                            m_CameraPositionVector.y,
                            m_CameraPositionVector.z);
        }

        if (glfwGetKey(t_pWindow, GLFW_KEY_D) == GLFW_PRESS)
        {
            m_CameraPositionVector += m_CameraRightVector * fCameraSpeed;
            ENGINE_INFO_LOG("\nD key pressed.\nX: {0}\nY: {1}\nZ: {2}",
                            m_CameraPositionVector.x,
                            m_CameraPositionVector.y,
                            m_CameraPositionVector.z);
        }
    }

    void CEditorCamera::CameraMouseMovementInput(GLFWwindow *t_pWindow)
    {
        double cursorPositionX = 0.0;
        double cursorPositionY = 0.0;
        glfwGetCursorPos(t_pWindow, &cursorPositionX, &cursorPositionY);

        m_CursorPositionX = static_cast<float>(cursorPositionX);
        m_CursorPositionY = static_cast<float>(cursorPositionY);

        if (!m_IsCursorPositionSet)
        {
            m_CursorLastPositionX = m_CursorPositionX;
            m_CursorLastPositionY = m_CursorPositionY;
            m_IsCursorPositionSet = true;
        }

        const float cursorOffsetX = m_CursorPositionX - m_CursorLastPositionX;
        const float cursorOffsetY = m_CursorLastPositionY - m_CursorPositionY;

        m_CursorLastPositionX = m_CursorPositionX;
        m_CursorLastPositionY = m_CursorPositionY;

        m_Pitch += cursorOffsetY * m_MouseSensitivity;
        m_Yaw += cursorOffsetX * m_MouseSensitivity;

        if (m_Pitch > 89.0f)
        {
            m_Pitch = 89.0f;
        }
        else if (m_Pitch < -89.0f)
        {
            m_Pitch = -89.0f;
        }

        UpdateCameraVectors();
    }

    glm::mat4 CEditorCamera::CalculateViewMatrix() const
    {
        return glm::lookAt(m_CameraPositionVector,
                           m_CameraPositionVector + m_CameraFrontVector,
                           m_CameraUpVector);
    }

    glm::mat4 CEditorCamera::CalculatePerspectiveProjectionMatrix(const CWindow &ct_pWindow) const
    {
        const float aspectRatio = static_cast<float>(ct_pWindow.GetWidth()) /
                                  static_cast<float>(ct_pWindow.GetHeight());
        constexpr float nearPlane = 0.1f;
        constexpr float farPlane = 100.0f;

        return glm::perspective(glm::radians(m_FOV), aspectRatio, nearPlane, farPlane);
    }

    void CEditorCamera::UpdateCameraVectors()
    {
        glm::vec3 cameraFrontVector(1.0f);
        cameraFrontVector.x = glm::cos(glm::radians(m_Yaw)) * glm::cos(glm::radians(m_Pitch));
        cameraFrontVector.y = glm::sin(glm::radians(m_Pitch));
        cameraFrontVector.z = glm::sin(glm::radians(m_Yaw)) * glm::cos(glm::radians(m_Pitch));
        m_CameraFrontVector = glm::normalize(cameraFrontVector);
        m_CameraRightVector = glm::normalize(glm::cross(m_CameraFrontVector, m_CameraWorldUpVector));
        m_CameraUpVector = glm::normalize(glm::cross(m_CameraRightVector, m_CameraFrontVector));
    }

} // namespace Engine
