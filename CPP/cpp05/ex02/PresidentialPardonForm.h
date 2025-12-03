#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm(const std::string &target);
    virtual void execute(const Bureaucrat &executor) const;

private:
    std::string target;
};

#endif // PRESIDENTIALPARDONFORM_H