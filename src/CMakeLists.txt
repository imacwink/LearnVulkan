if(BUILD_BASE MATCHES ON)
    message("Build VulkanBase ShareLib")
    add_subdirectory(base)
    add_subdirectory(basicengine)

    if(BUILD_QtExamples MATCHES ON)
        add_subdirectory(QtVulkanWindow)
    endif()
endif()
