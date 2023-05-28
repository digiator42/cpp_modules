/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:08 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/28 05:00:03 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain *brain;    
public:
    Dog();
    Dog(const std::string &name);
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    ~Dog();
    std::string getIdea(int index) const;
    void setIdea(int index, const std::string& idea);
    void makeSound() const;
};

#endif
