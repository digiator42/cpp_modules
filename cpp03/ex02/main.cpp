/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:25:14 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/26 20:13:02 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

	ClapTrap v("CLAP TRAP");
	ScavTrap b("NEW NAME");
	b.takeDamage(2);
	b.attack("Victime");
	v.takeDamage(2);
	v.beRepaired(3);
	b.attack("OLD");
	v.attack("OLD");
	ScavTrap c(b);
	c.guardGate();
	c.attack("nnn");
	FragTrap f("Frag");
	f.attack("NEW_FRAG");
	f.highFivesGuys();
	f.takeDamage(2);
}
