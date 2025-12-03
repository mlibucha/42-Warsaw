#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    Intern intern;
    Bureaucrat bureaucrat("John", 1);

    try {
        AForm* form1 = intern.makeForm("shrubbery creation", "Home");
        bureaucrat.signForm(*form1);
        bureaucrat.executeForm(*form1);
        delete form1;

        AForm* form2 = intern.makeForm("robotomy request", "Target");
        bureaucrat.signForm(*form2);
        bureaucrat.executeForm(*form2);
        delete form2;

        AForm* form3 = intern.makeForm("presidential pardon", "Alice");
        bureaucrat.signForm(*form3);
        bureaucrat.executeForm(*form3);
        delete form3;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}