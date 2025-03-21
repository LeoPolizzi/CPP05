/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:26:09 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/19 13:55:10 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <exception>
# include <iostream>
# include <string>

class	Bureaucrat;

class Form
{
  private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExec;

  public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExec);
	Form(Form const &src);

	Form &operator=(Form const &src);

	~Form();

	void beSigned(Bureaucrat &bureaucrat);

	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Form const &src);

#endif
