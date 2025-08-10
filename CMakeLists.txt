cmake_minimum_required(VERSION 3.16...3.28 FATAL_ERROR)
project(
    custom_engine
    VERSION 0.0.5
    LANGUAGES C CXX)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)

option(ENABLE_CLANG_FORMAT "Enable to add clang-format." ON)
option(ENABLE_CMAKE_FORMAT "Enable to add cmake-format." ON)

# Due to bug in spdlog library
if (MSVC)
    add_compile_options(/utf-8)
endif()

set(CUSTOM_ENGINE "${PROJECT_NAME}")
set(CUSTOM_ENGINE_ROOT_DIR "${PROJECT_SOURCE_DIR}")
set(CUSTOM_ENGINE_SRC_DIR "${CUSTOM_ENGINE_ROOT_DIR}/${CUSTOM_ENGINE}")
set(CUSTOM_ENGINE_INCLUDE_DIR
    "${CUSTOM_ENGINE_ROOT_DIR}/${CUSTOM_ENGINE}/include/${CUSTOM_ENGINE}")
set(CUSTOM_ENGINE_OUTPUT_DIR
    "${CUSTOM_ENGINE_ROOT_DIR}/bin/${CMAKE_SYSTEM_NAME}_${CMAKE_HOST_SYSTEM_PROCESSOR}/${CUSTOM_ENGINE}/$<CONFIG>"
)

list(APPEND CMAKE_MODULE_PATH "${CUSTOM_ENGINE_ROOT_DIR}/CMake")

include(Tools)
add_cmake_format_target()
add_clang_format_target()

include(AddGitSubmodule)
add_git_submodule("${CUSTOM_ENGINE_ROOT_DIR}/vendor/assimp")
add_git_submodule("${CUSTOM_ENGINE_ROOT_DIR}/vendor/glfw")
add_git_submodule("${CUSTOM_ENGINE_ROOT_DIR}/vendor/glm")
add_git_submodule("${CUSTOM_ENGINE_ROOT_DIR}/vendor/spdlog")
#add_git_submodule("${CUSTOM_ENGINE_ROOT_DIR}/vendor/googletest")

add_subdirectory("${CUSTOM_ENGINE_ROOT_DIR}/vendor/glad")
add_subdirectory("${CUSTOM_ENGINE}")
add_subdirectory(sandbox)
