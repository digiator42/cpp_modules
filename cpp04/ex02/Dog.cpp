/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:06 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/27 19:29:42 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const std::string &name) : Animal(name) {
    std::cout << "Dog constructor called" << std::endl;
    brain = new Brain();
}
Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}
Dog& Dog::operator=(const Dog &other) {
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

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << type << " barks" << std::endl;
}
