#include <gtest/gtest.h>
#include "Bureaucrat.hpp"
#include <sstream>

// Test case for constructor with valid grades.
// It should not throw any exception.
TEST(BureaucratConstructorTest, ValidGrades)
{
    try
    {
        Bureaucrat b1("Hermes", Bureaucrat::HIGHEST_GRADE);
        Bureaucrat b2("Morgan", Bureaucrat::LOWEST_GRADE);
        Bureaucrat b3("Dwight", 75);
    }
    catch (const std::exception &e)
    {
        FAIL() << "Constructor threw an exception with valid grades: " << e.what();
    }
}

// Test case for constructor throwing GradeTooHighException.
TEST(BureaucratConstructorTest, ThrowsGradeTooHigh)
{
    ASSERT_THROW(Bureaucrat("Too High", Bureaucrat::HIGHEST_GRADE - 1), Bureaucrat::GradeTooHighException);
    ASSERT_THROW(Bureaucrat("Zero Grade", 0), Bureaucrat::GradeTooHighException);
}

// Test case for constructor throwing GradeTooLowException.
TEST(BureaucratConstructorTest, ThrowsGradeTooLow)
{
    ASSERT_THROW(Bureaucrat("Too Low", Bureaucrat::LOWEST_GRADE + 1), Bureaucrat::GradeTooLowException);
    ASSERT_THROW(Bureaucrat("Very Low Grade", 200), Bureaucrat::GradeTooLowException);
}

// Test case for getters.
TEST(BureaucratGettersTest, Getters)
{
    Bureaucrat b("Zaphod", 42);
    EXPECT_EQ(b.getName(), "Zaphod");
    EXPECT_EQ(b.getGrade(), 42);
}

// Test case for incrementing grade.
TEST(BureaucratGradeManipulationTest, IncrementGrade)
{
    Bureaucrat b("Arthur", 100);
    b.incrementGrade();
    EXPECT_EQ(b.getGrade(), 99);
}

// Test case for incrementing grade at the highest limit.
TEST(BureaucratGradeManipulationTest, IncrementGradeAtLimit)
{
    Bureaucrat b("Ford", Bureaucrat::HIGHEST_GRADE);
    ASSERT_THROW(b.incrementGrade(), Bureaucrat::GradeTooHighException);
    EXPECT_EQ(b.getGrade(), Bureaucrat::HIGHEST_GRADE); // Grade should remain unchanged.
}

// Test case for decrementing grade.
TEST(BureaucratGradeManipulationTest, DecrementGrade)
{
    Bureaucrat b("Trillian", 50);
    b.decrementGrade();
    EXPECT_EQ(b.getGrade(), 51);
}

// Test case for decrementing grade at the lowest limit.
TEST(BureaucratGradeManipulationTest, DecrementGradeAtLimit)
{
    Bureaucrat b("Marvin", Bureaucrat::LOWEST_GRADE);
    ASSERT_THROW(b.decrementGrade(), Bureaucrat::GradeTooLowException);
    EXPECT_EQ(b.getGrade(), Bureaucrat::LOWEST_GRADE); // Grade should remain unchanged.
}

// Test case for the stream insertion operator.
TEST(BureaucratStreamOperatorTest, OutputFormat)
{
    Bureaucrat b("Slartibartfast", 133);
    std::stringstream ss;
    ss << b;
    EXPECT_EQ(ss.str(), "Slartibartfast, bureaucrat grade 133");
}

// Test case for copy constructor and assignment operator.
TEST(BureaucratOrthodoxCanonicalFormTest, CopyAndAssignment)
{
    Bureaucrat b1("Original", 75);

    // Test copy constructor
    Bureaucrat b2(b1);
    EXPECT_EQ(b2.getName(), "Original");
    EXPECT_EQ(b2.getGrade(), 75);

    // Test assignment operator
    Bureaucrat b3("New", 10);
    b3 = b1;
    // The name is const and should not be changed by the assignment operator.
    EXPECT_EQ(b3.getName(), "New");
    EXPECT_EQ(b3.getGrade(), 75);
}

// Test the what() message of the exceptions
TEST(BureaucratExceptionTest, WhatMessage)
{
    try {
        Bureaucrat("Test", 0);
        FAIL() << "Expected Bureaucrat::GradeTooHighException";
    } catch(const Bureaucrat::GradeTooHighException& e) {
        EXPECT_STREQ("Grade is too high", e.what());
    }

    try {
        Bureaucrat("Test", 151);
        FAIL() << "Expected Bureaucrat::GradeTooLowException";
    } catch(const Bureaucrat::GradeTooLowException& e) {
        EXPECT_STREQ("Grade is too low", e.what());
    }
}