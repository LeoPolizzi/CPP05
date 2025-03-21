/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:20:06 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/21 14:19:11 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "package.hpp"

int main() {

	Intern intern;

    Bureaucrat highRank("Alice", 1);
    Bureaucrat midRank("Bob", 45);
    Bureaucrat lowRank("Charlie", 150);

	std::cout << "\n--- Creating Forms ---\n" << std::endl;

	Form *pardon = intern.makeForm("presidential pardon", "target1");
	Form *robotomy = intern.makeForm("robotomy request", "target2");
	Form *shrubbery = intern.makeForm("shrubbery creation", "target3");

    std::cout << "\n--- Signing Forms ---\n" << std::endl;
    lowRank.signForm(pardon);
    midRank.signForm(robotomy);
    highRank.signForm(shrubbery);

    std::cout << "\n--- Executing Forms ---\n" << std::endl;
    lowRank.executeForm(pardon);
    midRank.executeForm(robotomy);
    highRank.executeForm(shrubbery);

	std::cout << "\n--- Destruction ---\n" << std::endl;

    return 0;
}
