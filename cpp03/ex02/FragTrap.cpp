/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:42:44 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/25 20:09:58 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap constructor called" << std::endl;
    _name = "NO NAME";
	hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "FragTrap Parameterized constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap & other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
    std::cout << "FragTrap assignation operator called" << std::endl;
    if (this != &rhs)
    {
        _name = rhs._name;
        hitPoints = rhs.hitPoints;
        energyPoints = rhs.energyPoints;
        attackDamage = rhs.attackDamage;
    }
    return *this;
}

void FragTrap::attack(const std::string &target)
{
    if (!energyPoints || !hitPoints)
    {
        std::cout << "FragTrap " << _name << " has no energy to attack!" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints ? energyPoints-- : energyPoints;
}
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " give you a high five" << std::endl;
}
