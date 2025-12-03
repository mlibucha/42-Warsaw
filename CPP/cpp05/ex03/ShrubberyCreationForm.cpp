#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (!this->getIsSigned())
        throw std::runtime_error("Form not signed");
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream outFile((target + "_shrubbery").c_str());
    if (outFile.is_open()) {
        outFile << "       _-_\n";
        outFile << "    _-_-_-_\n";
        outFile << "  _-_-_-_-_-_\n";
        outFile << "       |||\n";
        outFile << "       |||\n";
        outFile << "       |||\n";
        outFile.close();
        std::cout << "Shrubbery created at " << target << "_shrubbery" << std::endl;
    } else {
        throw std::runtime_error("Unable to open output file");
    }
}

const std::string &ShrubberyCreationForm::getTarget() const {
    return target;
}