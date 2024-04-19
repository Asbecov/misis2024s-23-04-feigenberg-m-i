add_executable(test_complex test_complex.cpp)

target_link_libraries(test_complex PRIVATE complex)

add_executable(test_rational test_rational.cpp)

target_link_libraries(test_rational PRIVATE rational)

add_executable(test_dynarr test_dynarr.cpp)

target_link_libraries(test_dynarr PRIVATE dynarr)

add_executable(test_stackarr test_stackarr.cpp)

target_link_libraries(test_stackarr PRIVATE stackarr)

add_executable(test_stacklst test_stacklst.cpp)

target_link_libraries(test_stacklst PRIVATE stacklst)

add_executable(test_queuelst test_queuelst.cpp)

target_link_libraries(test_queuelst PRIVATE queuelst)

add_executable(test_queuearr test_queuearr.cpp)

target_link_libraries(test_queuearr PRIVATE queuearr)

add_executable(test_queuelstpr test_queuelstpr.cpp)

target_link_libraries(test_queuelstpr PRIVATE queuelstpr)

add_executable(test_bitset test_bitset.cpp)

target_link_libraries(test_bitset PRIVATE bitset)

add_executable(test_stackarrt test_stackarrt.cpp)

target_link_libraries(test_stackarrt PUBLIC stackarrt)
