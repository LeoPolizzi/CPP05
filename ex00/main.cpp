/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:20:06 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/19 11:24:49 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *bureaucrat = new Bureaucrat("Michel", 1);

	std::cout << *bureaucrat << std::endl;
	bureaucrat->incrementGrade();
	std::cout << *bureaucrat << std::endl;
	for (int i = 0; i < 150; i++)
		bureaucrat->decrementGrade();
	std::cout << *bureaucrat << std::endl;

	delete bureaucrat;
	return (0);
}
