#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(const std::string &target);
    virtual ~RobotomyRequestForm();
    virtual void execute(const Bureaucrat &executor) const;

private:
    std::string target;
};

#endif // ROBOTOMYREQUESTFORM_H