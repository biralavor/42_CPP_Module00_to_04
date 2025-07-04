add_library(phonebook_lib
    src/Contact.cpp
    src/PhoneBook.cpp
    src/Printers.cpp
)

target_include_directories(phonebook_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)

# Create executable
add_executable(phonebook
    src/main.cpp
)

target_link_libraries(phonebook PRIVATE
    phonebook_lib
)