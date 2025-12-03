// PresidentialPardonForm.hpp
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm(const std::string &target);
    virtual ~PresidentialPardonForm(); // <-- add this declaration
    virtual void execute(const Bureaucrat &executor) const;
private:
    std::string target;

};

#endif // PRESIDENTIALPARDONFORM_HPP