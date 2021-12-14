cmake_minimum_required(VERSION 3.20)

project(myopengltest)

set(CONAN_DISABLE_CHECK_COMPILER True)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

conan_basic_setup()

add_executable(myopengltest main.cpp LoadShaders.cpp LoadShaders.h)

target_link_libraries(myopengltest ${CONAN_LIBS})
