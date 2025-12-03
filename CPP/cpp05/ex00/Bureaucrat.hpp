/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:19:09 by e                 #+#    #+#             */
/*   Updated: 2025/11/12 13:19:41 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
   private:
    const std::string _name;
    int               _grade; // 1 (highest) .. 150 (lowest)

   public:
    // Orthodox Canonical Form
    Bureaucrat();                                   // default
    Bureaucrat(const std::string& name, int grade); // param
    Bureaucrat(const Bureaucrat& other);            // copy
    Bureaucrat& operator=(const Bureaucrat& other); // assign
    ~Bureaucrat();                                  // dtor

    // Getters
    const std::string& getName() const;
    int                getGrade() const;

    // Grade manipulation
    void incrementGrade(); // 3 -> 2
    void decrementGrade(); // 3 -> 4

    // Exceptions
    class GradeTooHighException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        virtual const char* what() const throw();
    };
};

// Insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif // BUREAUCRAT_HPP