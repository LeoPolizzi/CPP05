/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:20:06 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/19 16:52:40 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "package.hpp"

int main() {
    Bureaucrat highRank("Alice", 1);
    Bureaucrat midRank("Bob", 45);
    Bureaucrat lowRank("Charlie", 150);

    ShrubberyCreationForm shrubbery("Home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Marvin");

    std::cout << "\n--- Signing Forms ---\n" << std::endl;
    lowRank.signForm(shrubbery);
    midRank.signForm(robotomy);
    highRank.signForm(pardon);

    std::cout << "\n--- Executing Forms ---\n" << std::endl;
    lowRank.executeForm(shrubbery);
    midRank.executeForm(robotomy);
    highRank.executeForm(pardon);

	std::cout << "\n--- Destruction ---\n" << std::endl;

    return 0;
}
