/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:02 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/26 05:58:03 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const std::string &name) : Animal(name) {

}
Cat::Cat(const Cat &other) : Animal(other) {
    
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
    std::cout << "Cat meows" << std::endl;
}
