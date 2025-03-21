/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:41:56 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/19 15:43:54 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm
{
  private:
	std::string _target;

	ShrubberyCreationForm();

  public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

	void execute(Bureaucrat const &executor) const;

	std::string getTarget() const;

	class FileNotOpenedException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

#endif
