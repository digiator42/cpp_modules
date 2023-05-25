/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:25:14 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/26 00:46:00 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

	ClapTrap v("CLAP TRAP");
	ScavTrap b;
	b.takeDamage(2);
	b.attack("dasda");
	v.takeDamage(2);
	v.beRepaired(3);
	b.attack("OLD");
	v.attack("OLD");
	ScavTrap c(b);
	c.guardGate();
	c.attack("nnn");
	FragTrap f("fds");
	f.attack("neahah");
	f.highFivesGuys();
	f.takeDamage(2);
}
