#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(const std::string &target);
    virtual ~RobotomyRequestForm();
    virtual void execute(const Bureaucrat &executor) const;
    const std::string &getTarget() const;
private:
    std::string target;
};

#endif // ROBOTOMYREQUESTFORM_HPP