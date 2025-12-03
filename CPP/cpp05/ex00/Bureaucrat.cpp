/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:19:06 by e                 #+#    #+#             */
/*   Updated: 2025/11/12 13:19:58 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Helpers
static void checkGradeOrThrow(int grade) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

// Orthodox Canonical Form
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name), _grade(grade) {
    checkGradeOrThrow(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        // _name is const and cannot be reassigned
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

// Getters
const std::string& Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

// Grade manipulation
void Bureaucrat::incrementGrade() {
    checkGradeOrThrow(_grade - 1);
    --_grade;
}

void Bureaucrat::decrementGrade() {
    checkGradeOrThrow(_grade + 1);
    ++_grade;
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade too low";
}

// Insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
    os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return os;
}