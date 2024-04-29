cmake_minimum_required(VERSION 3.22)
project(p38-euler)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(p38-euler src/main.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(p38-euler-test
        unit_tests/ATest.cpp
)
target_include_directories(p38-euler-test PRIVATE src)
target_link_libraries(p38-euler-test PRIVATE GTest::gtest GTest::gmock GTest::gmock_main)

include(GoogleTest)
gtest_discover_tests(p38-euler-test)
