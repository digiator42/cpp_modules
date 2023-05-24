/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:06:48 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/23 01:58:38 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : hitPoints(0), energyPoints(0), attackDamage(0)
{
    _name = "NULL";
	std::cout << "Default constructor called" << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(const std::string &name) : hitPoints(10), energyPoints(10), attackDamage(10)
{
    _name = name;
	std::cout << "Parameterized constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name) 
{
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
	std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if(this != &other)
        _name = other._name;
	std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string& target) 
{
   if(!hitPoints && !energyPoints){
        std::cout << "Clap trap " << _name << " has no points to attack " << target << std::endl;
        return;
   }
   attackDamage ? attackDamage-- : attackDamage;
   std::cout <<  "Clap trap " << _name << " attacks " << target << ", causing " << attackDamage 
        << " points of damage!" <<std::endl;
   hitPoints ? hitPoints-- : hitPoints;
   energyPoints ? energyPoints-- : energyPoints;
}

void ClapTrap::takeDamage(unsigned int amount) 
{
    if (hitPoints <= amount)
	{
		std::cout << "ClapTrap " << _name << " has been taking a significant damage and died :(" 
            <<std::endl;
		return;
	}
	hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage, and now has " 
        << hitPoints << " hit points.\n";
}

void ClapTrap::beRepaired(unsigned int amount) 
{
    if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left to repair itself" << std::endl;
		return;
	}
	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repaired " << amount << " points, and now has "
        << hitPoints << " hit points.\n";
}

ClapTrap::~ClapTrap() 
{
	std::cout << "Destructor called" << std::endl;
}
