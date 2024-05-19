set(CPP_FILES
    0001a.cpp
    0041a.cpp
    0058a.cpp
    0071a.cpp
    0118a.cpp
    0148a.cpp
    0610a.cpp
    0750a.cpp
    0977a.cpp
    1102a.cpp
    1704a.cpp
    1849a.cpp
    1915c.cpp
    1918a.cpp
    1925a.cpp
    1931a.cpp
    1937a.cpp
    1965a.cpp
    1328a.cpp
)

foreach(CPP_FILE ${CPP_FILES})
    get_filename_component(EXECUTABLE_NAME ${CPP_FILE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${CPP_FILE})
endforeach()