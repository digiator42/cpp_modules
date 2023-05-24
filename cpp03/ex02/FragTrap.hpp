/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:43:10 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/24 04:36:42 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
    	// Default constructor
    	FragTrap();
    	// Parameterized constructor
    	FragTrap(const std::string &name);
    	// Copy constructor
    	FragTrap(const FragTrap& other);
    	// Copy assignment operator
    	FragTrap& operator=(const FragTrap& other);
    	// Destructor
    	~FragTrap();
		void attack(const std::string &target);
        void highFivesGuys(void);
};

#endif