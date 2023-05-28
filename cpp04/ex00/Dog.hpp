/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:08 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/28 18:08:22 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(const std::string &name);
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    ~Dog();
    std::string getType() const;
    void makeSound() const;
};

#endif
