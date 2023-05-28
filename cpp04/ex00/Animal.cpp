/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:55:57 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/28 17:48:55 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
    std::cout << "Animal constructor called" << std::endl;
    type = "Animal";
}

Animal::Animal(const std::string &name) : type(name) {

}
Animal::Animal(const Animal &other) : type(other.type) {
    
}
Animal& Animal::operator=(const Animal &other) {
     if(this != &other)
        type = other.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const{
    return this->type;
}

void Animal::makeSound() const {
    std::cout << "Animal makes a sound" << std::endl;
}
