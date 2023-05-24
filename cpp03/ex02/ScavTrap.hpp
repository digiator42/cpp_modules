/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 01:45:57 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/24 04:36:40 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_H
# define SCAV_TRAP_H

#define RED "\e[1;31m"
#define GREEN "\e[1;32m"
#define RESET "\033[0m"
#define CYAN "\e[1;36m"
#define PURPLE "\e[1;35m"


#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	
public:
    // Default constructor
    ScavTrap();
    // Parameterized constructor
    ScavTrap(const std::string &name);
    // Copy constructor
    ScavTrap(const ScavTrap& other);
    // Copy assignment operator
    ScavTrap& operator=(const ScavTrap& other);
    // Destructor
    ~ScavTrap();
    void attack(const std::string & target);
    void guardGate();
};

#endif