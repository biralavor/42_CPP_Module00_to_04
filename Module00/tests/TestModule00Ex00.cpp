#include <gtest/gtest.h>
#include "../ex00/headers/Megaphone.hpp"

class MegaphoneTest : public ::testing::Test {
    protected:
    std::stringstream buffer;
    std::streambuf* oldCout;

    void SetUp() override {
        oldCout = std::cout.rdbuf(buffer.rdbuf());
    }

    void TearDown() override {
        std::cout.rdbuf(oldCout);
    }
};

// TEST_F(MegaphoneTest, NoArgumentsTest) {
//     char* argv[] = {(char*)"megaphone"};
//     int argc = 1;
    
//     megaphone(argc, argv);

//     EXPECT_EQ(buffer.str(), ">>> SHOUTING IS BAD <<<\n");
// }

// TEST_F(MegaphoneTest, SingleArgumentTest) {
//     char* argv[] = {(char*)"./megaphone", (char*)"hello\n"};
//     int argc = 2;
    
//     megaphone(argc, argv);

//     EXPECT_EQ(buffer.str(), "HELLO\n");
// }
