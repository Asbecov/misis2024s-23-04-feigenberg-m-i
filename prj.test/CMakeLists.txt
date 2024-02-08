add_executable(test_complex test_complex.cpp)

target_link_libraries(test_complex PRIVATE complex)

add_executable(test_rational test_rational.cpp)

target_link_libraries(test_rational PRIVATE rational)

add_executable(test_dynarr test_dynarr.cpp)

target_link_libraries(test_dynarr PRIVATE dynarr)