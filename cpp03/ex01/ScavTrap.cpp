/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 01:52:45 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/23 04:40:48 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() {
	std::cout << "Default constructor called" << std::endl;
}
// Parameterized constructor
ScavTrap::ScavTrap(const std::string &name) {
	std::cout << "Parameterized constructor called" << std::endl;
	_name = name;
	hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}
// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) {
	_name = other._name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
	std::cout << "Copy constructor called" << std::endl;
}
// Copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "Copy constructor called" << std::endl;
	if(this != &other)
		_name = other._name;
	std::cout << "Copy assignment operator called" << std::endl;
    return *this;	
}

void ScavTrap::guardGate() {
	std::cout << PURPLE << "ScavTrap is now in Gate keeper mode" << RESET << std::endl;
}
// Destructor
ScavTrap::~ScavTrap() {}