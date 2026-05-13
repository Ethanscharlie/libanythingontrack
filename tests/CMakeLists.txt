add_executable(aot_tests aotTests.c)
target_link_libraries(aot_tests PRIVATE anythingontrack)
add_test(NAME AOT_Tests COMMAND aot_tests)
