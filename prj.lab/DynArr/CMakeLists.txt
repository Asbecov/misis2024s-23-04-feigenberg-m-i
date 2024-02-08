add_library(dynarr DynArr.hpp DynArr.cpp)

set_property(TARGET dynarr PROPERTY CXX_STANDARD 20)

target_include_directories(dynarr PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS dynarr)