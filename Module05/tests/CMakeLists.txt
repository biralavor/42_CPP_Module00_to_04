find_package(GTest REQUIRED)

add_executable(Module05Tests
	TestModule05Ex00.cpp
)

target_link_libraries(Module05Tests PRIVATE
	GTest::GTest
	GTest::Main
	Bureaucrat_lib
)

include (GoogleTest)
gtest_discover_tests(Module05Tests)

add_test(
	NAME Module05_Ex00_Test
	COMMAND Module05Tests
)
