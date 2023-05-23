/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:25:14 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/23 00:08:38 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap h;
	ClapTrap f(h);
	ClapTrap f2("New");
	f2.takeDamage(0);
	f2.attack("Nih");
	f2.beRepaired(2);

}
