file(
    GLOB_RECURSE
    SOURCE_FILES
    CONFIGURE_DEPENDS
    "${CUSTOM_ENGINE_SRC_DIR}/*.hpp"
    "${CUSTOM_ENGINE_SRC_DIR}/*.cpp"
    "${CUSTOM_ENGINE_ROOT_DIR}/vendor/stb_image/stb_image.cpp")

add_library(${CUSTOM_ENGINE} SHARED ${SOURCE_FILES})

set_target_properties(
    ${CUSTOM_ENGINE}
    PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CUSTOM_ENGINE_OUTPUT_DIR}/"
               LIBRARY_OUTPUT_DIRECTORY "${CUSTOM_ENGINE_OUTPUT_DIR}/"
               RUNTIME_OUTPUT_DIRECTORY "${CUSTOM_ENGINE_OUTPUT_DIR}/")

target_compile_definitions(
    ${CUSTOM_ENGINE}
    PUBLIC $<$<BOOL:${WIN32}>:ENGINE_WINDOWS=1>
           $<$<BOOL:${UNIX}>:ENGINE_LINUX=1>
    PRIVATE ENGINE_BUILD=1
            GLFW_INCLUDE_NONE=1
            $<$<CONFIG:Debug>:ENGINE_DEBUG=1>
            $<$<CONFIG:RelWithDebInfo>:ENGINE_DEVELOPMENT=1>
            $<$<CONFIG:Release>:ENGINE_SHIP=1>)

target_include_directories(
    ${CUSTOM_ENGINE}
    PUBLIC "${CUSTOM_ENGINE_SRC_DIR}/"
           "${CUSTOM_ENGINE_ROOT_DIR}/vendor/assimp/include/"
           "${CUSTOM_ENGINE_ROOT_DIR}/vendor/glad/include/"
           "${CUSTOM_ENGINE_ROOT_DIR}/vendor/glfw/include/"
           "${CUSTOM_ENGINE_ROOT_DIR}/vendor/spdlog/include/"
           "${CUSTOM_ENGINE_ROOT_DIR}/vendor/glm/"
           #"${CUSTOM_ENGINE_ROOT_DIR}/vendor/googletest/googletest/include/"
           "${CUSTOM_ENGINE_ROOT_DIR}/vendor/stb_image/")

include(SetVendorOutput)
set_vendor_output("glad")
set_vendor_output("glfw")
#set_vendor_output("assimp")

target_precompile_headers(${CUSTOM_ENGINE} PRIVATE
                          "${CUSTOM_ENGINE_SRC_DIR}/pch.hpp")

target_link_libraries(
    ${CUSTOM_ENGINE}
    PUBLIC glfw
           #assimp
           glad
           #gtest
           OpenGL::GL)

include(CopyVendorOutput)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    #copy_vendor_output("assimp;*.lib")
    copy_vendor_output("glfw;glfw3d.lib")
    copy_vendor_output("glad;gladd.lib")
elseif()
    #copy_vendor_output("assimp;*.lib")
    copy_vendor_output("glfw;glfw3.lib")
    copy_vendor_output("glad;glad.lib")
endif()