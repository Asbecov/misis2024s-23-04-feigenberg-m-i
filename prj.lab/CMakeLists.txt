add_subdirectory(complex)

add_subdirectory(rational)

add_subdirectory(dynarr)

add_subdirectory(stackarr)

add_subdirectory(stacklst)

add_subdirectory(queuelst)

if (${CMAKE_PROJECT_VERSION} VERSION_GREATER_EQUAL 1.5.0)
    message("Building with QueueArr lib included, because the project version is greater than 1.5.0")
    add_subdirectory(queuearr)
endif()

if(${CMAKE_PROJECT_VERSION} VERSION_GREATER_EQUAL 1.6.0)
    message("Buildind with QueueLstPr lib included, as the project version is greater or equal to 1.6.0")
    add_subdirectory(queuelstpr)
endif()