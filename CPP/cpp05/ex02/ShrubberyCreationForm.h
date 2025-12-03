#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.h"
#include <string>

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm(const std::string &target);
    virtual ~ShrubberyCreationForm();
    
    virtual void execute(const Bureaucrat &executor) const;

private:
    std::string target;
};

#endif // SHRUBBERYCREATIONFORM_H