#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"   // <-- needed to call executor.getGrade()
#include <iostream>
#include <stdexcept>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon Form", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {} // matches header

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (!this->getIsSigned())
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException(); // or the appropriate exception
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}