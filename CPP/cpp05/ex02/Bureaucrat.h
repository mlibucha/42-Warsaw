#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <stdexcept>

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

#endif // BUREAUCRAT_H