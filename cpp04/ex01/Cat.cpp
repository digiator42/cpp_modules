/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:02 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/27 19:25:08 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const std::string &name) : Animal(name) {
    std::cout << "Dog constructor called" << std::endl;
    brain = new Brain();
}
Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain();
}
Cat& Cat::operator=(const Cat &other) {
    if(this != &other)
    {
        //shallow copy for string in stack 
        type = other.type; 
        //deallocating old memory
        delete this->brain;
        //deep copy of brain, need to deallocate it after use
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << type << " meows" << std::endl;
}
