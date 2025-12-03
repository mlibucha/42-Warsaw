#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request Form", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (!this->getIsSigned())
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::srand(std::time(NULL)); // use NULL/0 for C++98 compatibility
    if (std::rand() % 2)
        std::cout << this->target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << this->target << "." << std::endl;
}

const std::string &RobotomyRequestForm::getTarget() const {
    return target;
}