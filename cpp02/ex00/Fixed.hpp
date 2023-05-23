/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:21:06 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/23 23:03:53 by ahassan          ###   ########.fr       */
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
    Fixed(int val);
    // Copy constructor
    Fixed(const Fixed& other);
    // Copy assignment operator
    Fixed& operator=(const Fixed& other);
    // Destructor
    ~Fixed();

	int getRawBits() const;
	int setRawBits() const;
    Fixed operator=(const Fixed& other) const;
};

#endif