cmake_minimum_required(VERSION 3.10)
project(CPP_Module00Tests)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(PROJECT_VERSION 1.0)

find_package(GTest REQUIRED)

add_executable(Module00Tests
    TestModule00Ex00.cpp
    ../ex00/src/Megaphone.cpp
)

target_link_libraries(Module00Tests
    GTest::GTest
    GTest::Main
)

target_include_directories(Module00Tests PRIVATE
    ../ex00/headers
    ${GTEST_INCLUDE_DIRS}
)
