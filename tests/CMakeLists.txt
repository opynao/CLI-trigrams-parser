include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE TEST_SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

set(LIB_LIST_TESTS
    gtest_main
    gmock_main
    ${PROJECT_NAME}_lib
)
include_directories(${CMAKE_SOURCE_DIR}/include)
include(GoogleTest)

add_executable(${PROJECT_NAME}_tests ${TEST_SRC_LIST})
target_link_libraries(${PROJECT_NAME}_tests ${LIB_LIST_TESTS})
gtest_discover_tests(${PROJECT_NAME}_tests)
