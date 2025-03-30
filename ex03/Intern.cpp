/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:10:42 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/21 14:17:25 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &src)
{
	(void)src; // Nothing to copy in this class
	return (*this);
}

Form *Intern::_createShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::_createRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::_createPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(std::string formName, std::string target)
{
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form *(Intern::*formCreators[3])(std::string target) = {&Intern::_createShrubberyCreationForm, &Intern::_createRobotomyRequestForm, &Intern::_createPresidentialPardonForm};

	Form *form = NULL;

	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (formName == names[i])
			{
				form = (this->*formCreators[i])(target);
				std::cout << "Intern creates " << formName << std::endl;
				return (form);
			}
		}
	}
	catch (Intern::FormNotFoundException &e)
	{
		std::cerr << e.what() << formName << std::endl;
	}
	return (NULL);
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found : ");
}
