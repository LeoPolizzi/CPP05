/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:09:34 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/21 14:10:15 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>
# include <string>

class Intern
{
  private:
	Form *_createShrubberyCreationForm(std::string target);
	Form *_createRobotomyRequestForm(std::string target);
	Form *_createPresidentialPardonForm(std::string target);

  public:
	Intern();
	Intern(Intern const &src);
	~Intern();

	Intern &operator=(Intern const &src);

	Form *makeForm(std::string formName, std::string target);

	class FormNotFoundException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

#endif
