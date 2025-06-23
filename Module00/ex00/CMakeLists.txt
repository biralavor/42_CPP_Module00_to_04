# Create library for testing (without main function)
add_library(megaphone_lib
    src/Megaphone.cpp
)

target_include_directories(megaphone_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)

# Create executable
add_executable(megaphone
    src/main.cpp
)

target_link_libraries(megaphone PRIVATE
    megaphone_lib
)