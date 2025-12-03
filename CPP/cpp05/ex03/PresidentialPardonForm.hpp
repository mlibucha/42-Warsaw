#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm(const std::string &target);
    virtual ~PresidentialPardonForm();
    virtual void execute(const Bureaucrat &executor) const;
    const std::string &getTarget() const;
private:
    std::string target;
};

#endif // PRESIDENTIALPARDONFORM_HPP