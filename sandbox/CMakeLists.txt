cmake_minimum_required(VERSION 3.16...3.28 FATAL_ERROR)
project(
    sandbox
    VERSION 0.0.0
    LANGUAGES C CXX)
cmake_policy(SET CMP0072 NEW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SANDBOX "${PROJECT_NAME}")
set(SANDBOX_ROOT_DIR "${PROJECT_SOURCE_DIR}")
set(SANDBOX_OUTPUT_DIR
    "${SANDBOX_ROOT_DIR}/bin/${CMAKE_SYSTEM_NAME}_${CMAKE_HOST_SYSTEM_PROCESSOR}/${SANDBOX}/$<CONFIG>"
)

file(
    GLOB_RECURSE
    SOURCE_FILES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(${SANDBOX} ${SOURCE_FILES})

set_target_properties(${SANDBOX} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                            "${SANDBOX_OUTPUT_DIR}/")

target_include_directories(${SANDBOX} PUBLIC "${CUSTOM_ENGINE_INCLUDE_DIR}/")

target_link_libraries(${SANDBOX} PRIVATE ${CUSTOM_ENGINE})

# Copying custom_engine dll
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CUSTOM_ENGINE_DLL "${CUSTOM_ENGINE_OUTPUT_DIR}/custom_engined.dll")
elseif()
    set(CUSTOM_ENGINE_DLL "${CUSTOM_ENGINE_OUTPUT_DIR}/custom_engine.dll")
endif()

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CUSTOM_ENGINE_DLL}"
            "${SANDBOX_OUTPUT_DIR}/"
    COMMENT "Copying ${CUSTOM_ENGINE_DLL} to ${SANDBOX_OUTPUT_DIR}")
