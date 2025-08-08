function(copy_vendor_output data_list)
    list(GET data_list 0 target)
    list(GET data_list 1 target_output)

    # Build the path with generator expression for multi-config generators
    set(target_path "${CUSTOM_ENGINE_ROOT_DIR}/vendor/${target}/bin/${CMAKE_SYSTEM_NAME}-${CMAKE_HOST_SYSTEM_PROCESSOR}/${target}/$<CONFIG>/${target_output}")

    # Wrap file(GLOB) in if(GENERATOR_IS_MULTI_CONFIG) if you want to be fully robust, but for now:
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CUSTOM_ENGINE_OUTPUT_DIR}"
        COMMAND ${CMAKE_COMMAND} -E copy
            ${target_path}
            "${CUSTOM_ENGINE_OUTPUT_DIR}/"
        COMMENT "Copied ${target_output} from ${target}"
    )
endfunction()
