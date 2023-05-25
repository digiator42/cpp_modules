/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:55:57 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/25 06:22:44 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string &name) {

}
Animal::Animal(const Animal &other) {
    
}
Animal& Animal::operator=(const Animal &other) {

}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Animal makes a sound" << std::endl;
}
