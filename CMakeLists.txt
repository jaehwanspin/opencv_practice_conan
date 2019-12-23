cmake_minimum_required ( VERSION 3.10 )
project ( practice LANGUAGES CXX )

add_definitions( "-std=c++17" )

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.14/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
include( ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake )

conan_cmake_run(CONANFILE conanfile.txt
                BASIC_SETUP
                BUILD missing)

include_directories( include )
add_subdirectory ( src )