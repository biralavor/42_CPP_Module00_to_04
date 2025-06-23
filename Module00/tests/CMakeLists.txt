find_package(GTest REQUIRED)

# Create test executable
add_executable(Module00Tests
    TestModule00Ex00.cpp
)

# Configure test executable
target_link_libraries(Module00Tests PRIVATE
    GTest::GTest 
    GTest::Main
    megaphone_lib
)

# Register test
add_test(
    NAME Module00_Ex00_Test
    COMMAND Module00Tests
)