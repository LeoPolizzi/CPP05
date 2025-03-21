/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:43:59 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/19 16:50:41 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src.getName(), src.getGradeToSign(), src.getGradeToExec())
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	(void)src; // Nothing to copy in this class.
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
		throw (Form::GradeTooLowException());
	else if (this->getSigned() == false)
		throw (Form::FormNotSignedException());
	else
	{
		std::ofstream file (this->getTarget().append("_shrubbery").c_str());
		if (!file.is_open())
			throw (ShrubberyCreationForm::FileNotOpenedException());
		else
		{
			for (int i = 0; i < 10; i++)
			{
				file << "         v" << std::endl <<
						"        >X<" << std::endl <<
						"         A" << std::endl <<
						"        d$b" << std::endl <<
						"      .d\\$$b." << std::endl <<
						"    .d$i$$\\$$b." << std::endl <<
						"       d$$@b" << std::endl <<
						"      d\\$$$ib" << std::endl <<
						"    .d$$$\\$$$b" << std::endl <<
						"  .d$$@$$$$\\$$ib." << std::endl <<
						"      d$$i$$b" << std::endl <<
						"     d\\$$$$@$b" << std::endl <<
						"  .d$@$$\\$$$$$@b." << std::endl <<
						".d$$$$i$$$\\$$$$$$b." << std::endl <<
						"        ###" << std::endl <<
						"        ###" << std::endl <<
						"        ###" << std::endl <<
										 std::endl;
			}
			file.close();
		}
	}
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

const char *ShrubberyCreationForm::FileNotOpenedException::what() const throw()
{
	return ("File not opened");
}
