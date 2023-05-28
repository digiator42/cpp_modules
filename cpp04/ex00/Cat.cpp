/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:02 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/28 17:41:18 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const std::string &name) : Animal(name) {

}
Cat::Cat(const Cat &other) : Animal(other) {
    
}
Cat& Cat::operator=(const Cat &other) {
     if(this != &other)
        type = other.type;
    return *this;
}

std::string Cat::getType() const {
    return type;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Cat meows" << std::endl;
}
