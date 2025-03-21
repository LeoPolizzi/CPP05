/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:08:04 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/19 11:25:24 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Bureaucrat default constuctor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat " << _name << " created" << std::endl;
	try
	{
		this->setGrade(grade);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.error() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.error() << std::endl;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &src)
		this->_grade = src.getGrade();
	return (*this);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	try
	{
		this->setGrade(this->_grade - 1);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.error() << std::endl;
	}
}

void Bureaucrat::decrementGrade(void)
{
	try
	{
		this->setGrade(this->_grade + 1);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.error() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::error() const throw()
{
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::error() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (o);
}
