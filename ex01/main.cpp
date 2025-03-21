/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:20:06 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/19 13:41:27 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat john("John", 50);
	Bureaucrat jane("Jane", 1);
	Bureaucrat bob("Bob", 151);

	Form formA("FormA", 30, 50);

	std::cout << john << std::endl;
	std::cout << jane << std::endl;
	std::cout << formA << std::endl;

	john.signForm(formA);
	jane.signForm(formA);
	bob.signForm(formA);
	return (0);
}
