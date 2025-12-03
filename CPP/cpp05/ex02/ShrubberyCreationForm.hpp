// ShrubberyCreationForm.hpp
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm(const std::string &target);
    virtual ~ShrubberyCreationForm();
    virtual void execute(const Bureaucrat &executor) const;
    const std::string &getTarget() const; // <-- add this declaration
private:
    std::string target;

};

#endif // SHRUBBERYCREATIONFORM_HPP