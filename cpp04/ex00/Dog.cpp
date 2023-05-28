/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:06 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/28 18:08:14 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const std::string &name) : Animal(name) {

}
Dog::Dog(const Dog &other) : Animal(other) {
    
}
Dog& Dog::operator=(const Dog &other) {
     if(this != &other)
        type = other.type;
    return *this;
}

std::string Dog::getType() const {
    return type;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Dog barks" << std::endl;
}
