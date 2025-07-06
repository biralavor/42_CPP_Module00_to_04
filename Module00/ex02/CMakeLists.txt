set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(thejobofyourdreams_lib
    src/Account.cpp
)

target_include_directories(thejobofyourdreams_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)

add_executable(thejobofyourdreams
    src/tests.cpp
)

target_link_libraries(thejobofyourdreams PRIVATE
    thejobofyourdreams_lib
)
