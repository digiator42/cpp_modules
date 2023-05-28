/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:13 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/28 18:03:36 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal constructor called" << std::endl;
    type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const std::string &name) : type(name) {

}
WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
    
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
     if(this != &other)
        type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const{
    return this->type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes a sound" << std::endl;
}
