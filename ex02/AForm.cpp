/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:37:33 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/19 13:55:30 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150),
	_gradeToExec(150)
{
	std::cout << "Form default constuctor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name),
	_signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "Form " << this->_name << " created" << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw (AForm::GradeTooHighException());
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(AForm const &src) : _name(src.getName()), _signed(src.getSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec())
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
}

AForm::~AForm()
{
	std::cout << "Form " << this->_name << " destroyed" << std::endl;
}

AForm &AForm::operator=(AForm const &src)
{
	std::cout << "Form assignation operator called" << std::endl;
	(void)src; // Nothing to copy in this class.
	return (*this);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw (AForm::GradeTooLowException());
	else if (this->_signed)
		std::cout << "Form " << this->_name << " is already signed" << std::endl;
	else
	{
		this->_signed = true;
		std::cout << "Form " << this->_name << " has been signed by " << bureaucrat.getName() << std::endl;
	}
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_signed)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->_gradeToExec)
		throw (AForm::GradeTooLowException());
	else
		std::cout << "Form " << this->_name << " has been executed by " << executor.getName() << std::endl;
}

std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

int		AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int		AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &o, AForm const &src)
{
	o << "Form " << src.getName() << " is ";
	if (src.getSigned())
		o << "signed";
	else
		o << "not signed";
	o << " and requires grade " << src.getGradeToSign() << " to be signed and grade " << src.getGradeToExec() << " to be executed" << std::endl;
	return (o);
}
