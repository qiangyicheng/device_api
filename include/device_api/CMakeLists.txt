if(ENABLE_WOLFRAM_SCRIPT)
    ##device_api_headers

    set(DEVICE_API_HEADERS_GENERATED_LIST 
        device_api_cublas.h
        device_api_cuda_device.h  
        device_api_cuda_rtc.h      
        device_api_cudnn.h  
        device_api_curand.h    
        device_api_cucomplex.h  
        device_api_cuda_driver.h  
        device_api_cuda_runtime.h  
        device_api_cufft.h  
        device_api_cusparse.h
    )

    macro(add_prefix prefix list_name)
    set(${list_name}_TMP)
    foreach(l IN LISTS ${list_name})
       list(APPEND ${list_name}_TMP ${prefix}${l} )
    endforeach()
 
    set(${list_name} ${${list_name}_TMP})
    unset(${list_name}_TMP)
    endmacro(add_prefix)

    set(DEVICE_API_HEADERS_GENERATED_LIST_FULL_PATH ${DEVICE_API_HEADERS_GENERATED_LIST})
    add_prefix(${CMAKE_CURRENT_SOURCE_DIR}/ DEVICE_API_HEADERS_GENERATED_LIST_FULL_PATH)

    set(CURRENT_TARGET_NAME device_api_headers)
    set(CURRENT_GENERATOR_DIR ${PROJECT_SOURCE_DIR}/generator/${CURRENT_TARGET_NAME})
    add_custom_command(
        OUTPUT 
        ${DEVICE_API_HEADERS_GENERATED_LIST_FULL_PATH}
        COMMAND 
            wolframscript -file 
            ${CURRENT_GENERATOR_DIR}/${CURRENT_TARGET_NAME}.wls
            ${hipify_SOURCE_DIR}/doc/markdown
            ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS 
            ${CURRENT_GENERATOR_DIR}/${CURRENT_TARGET_NAME}.wls
        WORKING_DIRECTORY
            ${CMAKE_CURRENT_SOURCE_DIR}
        VERBATIM
    )
    add_custom_target(${CURRENT_TARGET_NAME}
        DEPENDS 
            ${DEVICE_API_HEADERS_GENERATED_LIST_FULL_PATH}
            ${WOLFRAM_SCRIPT_TARGET_LIST}
    )
    append_wolfram_script_target_list(${CURRENT_TARGET_NAME})

    ##
    add_dependencies(${PROJECT_NAME} device_api_headers)
endif()

target_sources(${PROJECT_NAME}
    INTERFACE
    device_api_cub.h
    device_api_helper.h
    #device_api_cublas.h ## not included, since the dependency is set by add_dependencies before (which has a private scope)
)