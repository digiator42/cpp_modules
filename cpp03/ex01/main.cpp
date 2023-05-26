/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:25:14 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/26 20:04:18 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

    ScavTrap scav("Shawrma");
    ScavTrap scav2("Shish Tawook");
    ScavTrap scavy(scav);
    scavy.attack("Potato");
    scav.attack("Potato");
    scav.takeDamage(0);
    scav.beRepaired(100);
    scav.guardGate();
    /*------------testing parent copy constructor------------*/
    ScavTrap scavx;
    ScavTrap scavy2(scavx);
    scavx.attack("Potato");
}
