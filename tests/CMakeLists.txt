add_executable(aot_tests aotTests.c)
target_link_libraries(aot_tests PRIVATE anythingontrack)

add_test(NAME ClearTestLog COMMAND aot_tests ClearTestLog)
add_test(NAME CurrentDate COMMAND aot_tests CurrentDate)
