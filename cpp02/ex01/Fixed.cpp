/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:06:48 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/22 21:26:15 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}
// Parameterized constructor
Fixed::Fixed(const int val) : value(val * 256) {
    std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float val) : value(roundf(val * 256)) {
    std::cout << "Float constructor called" << std::endl;
}
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
int Fixed::getValue(void) const {
    return value;
}
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
    return value;
}
void Fixed::setRawBits(const int raw) {
        value = raw;
}
float Fixed::toFloat(void) const {
    return static_cast<float>(value) / 256;
}
int Fixed::toInt(void) const {
    return static_cast<int>(value) / 256;
}
std::ostream &operator<<(std::ostream &out, const Fixed &fp){
    out << fp.toFloat();
    return out;
}
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
