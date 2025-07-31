function(copy_vendor_output data_list)

    list(GET data_list 0 target)
    list(GET data_list 1 target_output)

    file(GLOB FILE
    "${CUSTOM_ENGINE_ROOT_DIR}/vendor/${target}/bin/${CMAKE_SYSTEM_NAME}-${CMAKE_HOST_SYSTEM_PROCESSOR}/${target}/${CMAKE_BUILD_TYPE}/${target_output}"
    )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CUSTOM_ENGINE_OUTPUT_DIR}"
        COMMAND ${CMAKE_COMMAND} -E copy
        "${FILE}"
        "${CUSTOM_ENGINE_OUTPUT_DIR}"
        COMMENT "Copied ${target_output}"
    )

endfunction()