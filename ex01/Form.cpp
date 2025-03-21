/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:37:33 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/19 13:55:30 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150),
	_gradeToExec(150)
{
	std::cout << "Form default constuctor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name),
	_signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "Form " << this->_name << " created" << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw (Form::GradeTooHighException());
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(Form const &src) : _name(src.getName()), _signed(src.getSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec())
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
}

Form::~Form()
{
	std::cout << "Form " << this->_name << " destroyed" << std::endl;
}

Form &Form::operator=(Form const &src)
{
	std::cout << "Form assignation operator called" << std::endl;
	(void)src; // Nothing to copy in this class.
	return (*this);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw (Form::GradeTooLowException());
	else if (this->_signed)
		std::cout << "Form " << this->_name << " is already signed" << std::endl;
	else
	{
		this->_signed = true;
		std::cout << "Form " << this->_name << " has been signed by " << bureaucrat.getName() << std::endl;
	}
}

std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

int		Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int		Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &o, Form const &src)
{
	o << "Form " << src.getName() << " is ";
	if (src.getSigned())
		o << "signed";
	else
		o << "not signed";
	o << " and requires grade " << src.getGradeToSign() << " to be signed and grade " << src.getGradeToExec() << " to be executed" << std::endl;
	return (o);
}
