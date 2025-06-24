#include <gtest/gtest.h>
#include "../ex00/headers/Megaphone.hpp"

class MegaphoneTest : public ::testing::Test {
    protected:
};

TEST_F(MegaphoneTest, NoArgumentsTest) {
    char* argv[] = {(char*)"megaphone"};
    int argc = 1;
    
    std::string result = megaphone(argc, argv);

    EXPECT_EQ(result, ">>> SHOUTING IS BAD <<<");
}

TEST_F(MegaphoneTest, SingleArgumentTest) {
    char* argv[] = {(char*)"./megaphone", (char*)"hello"};
    int argc = 2;
    
    std::string result = megaphone(argc, argv);

    EXPECT_EQ(result, "HELLO");
}

TEST_F(MegaphoneTest, DoubleArgumentsTest) {
    char* argv[] = {(char*)"./megaphone",
                    (char*)"Forty", (char*)"Two",
                    nullptr};
    int argc = 0;
    while (argv[argc] != nullptr)
        argc++;
    std::string result = megaphone(argc, argv);

    EXPECT_EQ(result, "FORTY TWO");
}

TEST_F(MegaphoneTest, MultipleArgumentsTest) {
    char* argv[] = {(char*)"./megaphone",
                    (char*)"Forty", (char*)"Two", (char*)"is", (char*)"awesome",
                    nullptr};
    int argc = 0;
    while (argv[argc] != nullptr)
        argc++;
    
    std::string result = megaphone(argc, argv);

    EXPECT_EQ(result, "FORTY TWO IS AWESOME");
}

TEST_F(MegaphoneTest, ArgumentsWithNumbersTest) {
    char* argv[] = {(char*)"./megaphone",
                    (char*)"Hi", (char*)"42",
                    nullptr};
    int argc = 0;
    while (argv[argc] != nullptr)
        argc++;
    
    std::string result = megaphone(argc, argv);

    EXPECT_EQ(result, "HI 42");
}