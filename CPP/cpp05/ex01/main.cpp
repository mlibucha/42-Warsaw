#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("John Doe", 50);
        Form form("Form A", 45, 30);

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        bureaucrat.signForm(form);
        std::cout << form << std::endl;

        // Testing exception handling
        Bureaucrat lowGradeBureaucrat("Jane Doe", 150);
        lowGradeBureaucrat.signForm(form); // This should throw an exception

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}