/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:02 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/28 04:44:47 by ahassan          ###   ########.fr       */
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
    brain = new Brain(*other.brain);
}
Cat& Cat::operator=(const Cat &other) {
    if(this != &other)
    {
        type = other.type; 
        //deallocating old memory
        delete this->brain;
        //deep copy of brain, need to deallocate it after use
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

std::string Cat::getIdea(int index) const {
    return brain->getIdea(index);
}

void Cat::setIdea(int index, const std::string& idea){
    brain->setIdea(index, idea);
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << type << " meows" << std::endl;
}
