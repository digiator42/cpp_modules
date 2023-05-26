/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:18 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/25 06:38:50 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const std::string &name) : WrongAnimal(name) {

}
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    
}
WrongCat& WrongCat::operator=(const WrongCat &other) {
     if(this != &other)
        type = other.type;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat makes a sound like a WrongAnimal" << std::endl;
}
