/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 01:52:45 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/26 00:49:17 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap("NO NAME") {
	hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}
// Parameterized constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_name = name;
	hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
	std::cout << "ScavTrap Parameterized constructor called" << std::endl;
}
// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}
// Copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if(this != &other)
	{
		_name = other._name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    return *this;
}

void ScavTrap::guardGate() 
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string & target)
{
    if (!energyPoints || !hitPoints)
    {
        std::cout << "ScavTrap " << _name << " has no energy to attack!" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints ? energyPoints-- : energyPoints;
}
// Destructor
ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}