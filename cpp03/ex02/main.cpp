/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:25:14 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/24 22:58:47 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

	ScavTrap b;
	b.takeDamage(2);
	b.attack("OLD");
	// ScavTrap c(b);
	// c.guardGate();
	// c.attack("nnn");
	// FragTrap f("fds");
	// f.attack("neahah");
	// f.highFivesGuys();
	// f.takeDamage(2);
}
