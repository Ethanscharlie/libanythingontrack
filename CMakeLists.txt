cmake_minimum_required(VERSION 3.16)

project(anythingontrack LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_library(anythingontrack src/aot.c)

target_include_directories(anythingontrack PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

enable_testing()
add_subdirectory(tests)
