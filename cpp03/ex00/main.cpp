/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:25:14 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/25 19:20:18 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap h;
	ClapTrap f(h);
	ClapTrap f2("New");
	f2.takeDamage(10);
	f2.attack("Nih");
	f2.beRepaired(2);
	f2.attack("Nih");
}
