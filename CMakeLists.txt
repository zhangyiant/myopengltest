cmake_minimum_required(VERSION 3.20)

project(myopengltest)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

conan_basic_setup()

add_executable(myopengltest main.cpp LoadShaders.cpp LoadShaders.h)

target_link_libraries(myopengltest ${CONAN_LIBS})
