find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(pet_project pet_project.cpp)
target_link_libraries(pet_project ${OpenCV_LIBS})