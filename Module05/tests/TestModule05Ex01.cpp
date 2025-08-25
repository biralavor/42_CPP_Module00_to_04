/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestModule05Ex01.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:18:15 by umeneses          #+#    #+#             */
/*   Updated: 2025/08/23 22:24:02 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <sstream>

// --- Bureaucrat Tests ---

TEST(BureaucratTest, DefaultConstructor) {
    Bureaucrat b;
    EXPECT_EQ(b.getName(), "Default");
    EXPECT_EQ(b.getGrade(), 150);
}

TEST(BureaucratTest, ParameterizedConstructorValid) {
    Bureaucrat b("Alice", 42);
    EXPECT_EQ(b.getName(), "Alice");
    EXPECT_EQ(b.getGrade(), 42);
}

TEST(BureaucratTest, ConstructorGradeTooHigh) {
    EXPECT_THROW(Bureaucrat b("Bob", 0), Bureaucrat::GradeTooHighException);
}

TEST(BureaucratTest, ConstructorGradeTooLow) {
    EXPECT_THROW(Bureaucrat b("Charlie", 151), Bureaucrat::GradeTooLowException);
}

TEST(BureaucratTest, ConstructorGradeBoundary) {
    EXPECT_NO_THROW(Bureaucrat b1("David", 1));
    EXPECT_NO_THROW(Bureaucrat b2("Eve", 150));
}

TEST(BureaucratTest, CopyConstructor) {
    Bureaucrat b1("Frank", 75);
    Bureaucrat b2(b1);
    EXPECT_EQ(b2.getName(), "Frank");
    EXPECT_EQ(b2.getGrade(), 75);
}

TEST(BureaucratTest, AssignmentOperator) {
    Bureaucrat b1("Grace", 100);
    Bureaucrat b2("Heidi", 50);
    b2 = b1;
    EXPECT_EQ(b2.getName(), "Heidi"); // Name is const, should not change
    EXPECT_EQ(b2.getGrade(), 100);
}

TEST(BureaucratTest, IncrementGrade) {
    Bureaucrat b("Ivan", 2);
    b.incrementGrade();
    EXPECT_EQ(b.getGrade(), 1);
}

TEST(BureaucratTest, IncrementGradeThrows) {
    Bureaucrat b("Judy", 1);
    EXPECT_THROW(b.incrementGrade(), Bureaucrat::GradeTooHighException);
}

TEST(BureaucratTest, DecrementGrade) {
    Bureaucrat b("Mallory", 149);
    b.decrementGrade();
    EXPECT_EQ(b.getGrade(), 150);
}

TEST(BureaucratTest, DecrementGradeThrows) {
    Bureaucrat b("Niaj", 150);
    EXPECT_THROW(b.decrementGrade(), Bureaucrat::GradeTooLowException);
}

TEST(BureaucratTest, StreamInsertion) {
    Bureaucrat b("Oscar", 42);
    std::stringstream ss;
    ss << b;
    EXPECT_EQ(ss.str(), "Oscar, bureaucrat grade 42");
}

// --- Form Tests ---

TEST(FormTest, DefaultConstructor) {
    Form f;
    EXPECT_EQ(f.getName(), "Default");
    EXPECT_FALSE(f.getSignature());
    EXPECT_EQ(f.getGradeToSign(), 150);
    EXPECT_EQ(f.getGradeToExecute(), 150);
}

TEST(FormTest, ParameterizedConstructorValid) {
    Form f("F1", 50, 100);
    EXPECT_EQ(f.getName(), "F1");
    EXPECT_FALSE(f.getSignature());
    EXPECT_EQ(f.getGradeToSign(), 50);
    EXPECT_EQ(f.getGradeToExecute(), 100);
}

TEST(FormTest, ConstructorGradeTooHigh) {
    EXPECT_THROW(Form f("F2", 0, 100), Form::GradeTooHighException);
    EXPECT_THROW(Form f("F3", 50, 0), Form::GradeTooHighException);
}

TEST(FormTest, ConstructorGradeTooLow) {
    EXPECT_THROW(Form f("F4", 151, 100), Form::GradeTooLowException);
    EXPECT_THROW(Form f("F5", 50, 151), Form::GradeTooLowException);
}

TEST(FormTest, CopyConstructor) {
    Form f1("F6", 42, 84);
    Bureaucrat b("Signer", 40);
    f1.beSigned(b);
    Form f2(f1);

    EXPECT_EQ(f2.getName(), "F6");
    EXPECT_TRUE(f2.getSignature());
    EXPECT_EQ(f2.getGradeToSign(), 42);
    EXPECT_EQ(f2.getGradeToExecute(), 84);
}

TEST(FormTest, BeSigned) {
    Bureaucrat b_high("Peter", 50);
    Bureaucrat b_low("Roger", 60);
    Form f("F9", 50, 100);

    EXPECT_FALSE(f.getSignature());
    EXPECT_THROW(f.beSigned(b_low), Form::GradeTooLowException);
    EXPECT_FALSE(f.getSignature());

    EXPECT_NO_THROW(f.beSigned(b_high));
    EXPECT_TRUE(f.getSignature());
}

TEST(FormTest, SignFormIntegration) {
    Bureaucrat b_can_sign("Samantha", 25);
    Bureaucrat b_cannot_sign("Thomas", 35);
    Form f("F12", 30, 60);

    b_cannot_sign.signForm(f);
    EXPECT_FALSE(f.getSignature());

    b_can_sign.signForm(f);
    EXPECT_TRUE(f.getSignature());
}
