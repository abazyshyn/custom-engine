cmake_minimum_required(VERSION 3.16...3.28 FATAL_ERROR)
project(custom_engine VERSION 0.0.5 LANGUAGES C CXX)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CUSTOM_ENGINE "${PROJECT_NAME}")
set(CUSTOM_ENGINE_ROOT_DIR "${PROJECT_SOURCE_DIR}")
set(CUSTOM_ENGINE_SRC_DIR "${CUSTOM_ENGINE_ROOT_DIR}/src")
set(CUSTOM_ENGINE_INCLUDE_DIR "${CUSTOM_ENGINE_ROOT_DIR}/src/include/${CUSTOM_ENGINE}")
set(CUSTOM_ENGINE_OUTPUT_DIR "${CUSTOM_ENGINE_ROOT_DIR}/bin/${CMAKE_SYSTEM_NAME}_${CMAKE_HOST_SYSTEM_PROCESSOR}/${CUSTOM_ENGINE}/$<CONFIG>/")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(AddGitSubmodule)
add_git_submodule("${CUSTOM_ENGINE_ROOT_DIR}/vendor/assimp")
add_git_submodule("${CUSTOM_ENGINE_ROOT_DIR}/vendor/glfw")
add_git_submodule("${CUSTOM_ENGINE_ROOT_DIR}/vendor/glm")
#add_git_submodule("${CUSTOM_ENGINE_ROOT_DIR}/vendor/googletest")

add_subdirectory("${CUSTOM_ENGINE_ROOT_DIR}/vendor/glad")
add_subdirectory(src)
add_subdirectory(sandbox)