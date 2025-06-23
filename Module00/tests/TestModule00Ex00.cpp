#include <gtest/gtest.h>
#include "../ex00/headers/Megaphone.hpp"

class MegaphoneTest : public ::testing::Test {
    protected:
    std::stringstream buffer;
    std::streambuf* oldCout;

    void SetUp() override {
        buffer.str("");
        buffer.clear();
        oldCout = std::cout.rdbuf(buffer.rdbuf());
    }

    void TearDown() override {
        std::cout.rdbuf(oldCout);
    }
};

TEST_F(MegaphoneTest, NoArgumentsTest) {
    char* argv[] = {(char*)"megaphone"};
    int argc = 1;
    
    megaphone(argc, argv);

    EXPECT_EQ(buffer.str(), ">>> SHOUTING IS BAD <<<\n");
}

TEST_F(MegaphoneTest, SingleArgumentTest) {
    char* argv[] = {(char*)"./megaphone", (char*)"hello"};
    int argc = 2;
    
    megaphone(argc, argv);

    EXPECT_EQ(buffer.str(), "HELLO");
}

TEST_F(MegaphoneTest, DoubleArgumentsTest) {
    char* argv[] = {(char*)"./megaphone", (char*)"Forty", (char*)"Two"};
    int argc = 0;
    while (argv[argc] != nullptr)
        argc++;
    argc++;
    megaphone(argc, argv);

    EXPECT_EQ(buffer.str(), "FORTY TWO");
}

TEST_F(MegaphoneTest, MultipleArgumentsTest) {
    char* argv[] = {(char*)"./megaphone", (char*)"Forty", (char*)"Two", (char*)"is", (char*)"awesome"};
    int argc = 5;
    
    megaphone(argc, argv);

    EXPECT_EQ(buffer.str(), "FORTY TWO IS AWESOME");
}

TEST_F(MegaphoneTest, ArgumentsWithNumbersTest) {
    char* argv[] = {(char*)"./megaphone", (char*)"Hi", (char*)"42"};
    int argc = 3;
    
    megaphone(argc, argv);

    EXPECT_EQ(buffer.str(), "HI 42");
}