/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:55:57 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/28 17:50:36 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string &name) : type(name) {
    std::cout << "Animal Para constructor called" << std::endl;

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
