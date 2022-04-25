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

    set(CURRENT_TARGET_NAME device_api_headers)
    set(CURRENT_GENERATOR_DIR ${PROJECT_SOURCE_DIR}/generator/${CURRENT_TARGET_NAME})
    add_custom_command(
        OUTPUT 
        ${DEVICE_API_HEADERS_GENERATED_LIST}
        COMMAND 
            wolframscript -file 
            ${CURRENT_GENERATOR_DIR}/${CURRENT_TARGET_NAME}.wls
            ${hipify_SOURCE_DIR}/doc/markdown
            ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS 
            ${CURRENT_GENERATOR_DIR}/${CURRENT_TARGET_NAME}.wls
        VERBATIM
    )
    add_custom_target(${CURRENT_TARGET_NAME}
        DEPENDS 
            ${DEVICE_API_HEADERS_GENERATED_LIST}
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