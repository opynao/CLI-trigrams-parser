cmake_minimum_required(VERSION 3.16...3.23)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId}
    VERSION 0.0.1
    LANGUAGES CXX C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(${PROJECT_NAME}_lib ${SRC_FILES})
add_executable(${PROJECT_NAME} ${SRC_FILES})

option(ENABLE_TESTS "Set to ON to enable building of tests" ON)

if(ENABLE_TESTS)
    message(STATUS "Building of tests is enabled")
    enable_testing()
    add_subdirectory(tests)
endif()
