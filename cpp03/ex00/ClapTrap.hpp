/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:21:06 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/22 23:52:28 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
# define CLAP_TRAP_H

#include <iostream>

class ClapTrap {
	
private:
    std::string _name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    // Default constructor
    ClapTrap();
    // Parameterized constructor
    ClapTrap(const std::string &name);
    // Copy constructor
    ClapTrap(const ClapTrap& other);
    // Copy assignment operator
    ClapTrap& operator=(const ClapTrap& other);
    // Destructor
    ~ClapTrap();
    
    ClapTrap operator=(const ClapTrap& other) const;
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif