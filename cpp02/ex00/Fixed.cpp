/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:06:48 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/22 02:57:22 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}
// Parameterized constructor
Fixed::Fixed(int val) : value(val) {}
// Copy constructor
Fixed::Fixed(const Fixed& other) : value(other.value) {
	std::cout << "Copy constructor called" << std::endl;
}
// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        value = other.value;
	std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}
// Destructor
int Fixed::getValue() const {
    return value;
}
int Fixed::getRawBits() const {
		std::cout << "getRawBits member function called" << std::endl;
        return value;
    }
int Fixed::setRawBits() const {
        return value;
    }
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
