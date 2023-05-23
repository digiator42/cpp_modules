/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:21:06 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/22 18:53:13 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_POINT_H
# define FIXED_POINT_H

#include <iostream>

class Fixed {
	
private:
    int value;
    static const int fb = 8;

public:
    // Default constructor
    Fixed();
    // Parameterized constructor
    Fixed(const int val);
    Fixed(const float val);
    // Copy constructor
    Fixed(const Fixed& other);
    // Copy assignment operator
    Fixed& operator=(const Fixed& other);
    // Destructor
    ~Fixed();

    int getValue() const;
	int getRawBits() const;
	void setRawBits(const int raw);
    float toFloat(void) const;
    int toInt(void) const;

    bool operator>(const Fixed& other);
    bool operator<(const Fixed& other);
    bool operator>=(const Fixed& other);
    bool operator<=(const Fixed& other);
    bool operator==(const Fixed& other);
    bool operator!=(const Fixed& other);
    
    Fixed operator+(const Fixed& other);
    Fixed operator-(const Fixed& other);
    Fixed operator*(const Fixed& other);
    Fixed operator/(const Fixed& other);
    
    Fixed& operator++();
    Fixed& operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    // Static member functions
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &in);

#endif