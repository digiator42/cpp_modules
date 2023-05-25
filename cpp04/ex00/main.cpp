/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:11 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/25 06:00:10 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    Animal animal;
    animal.makeSound();

    std::cout << "---------------------" << std::endl;

    Dog dog;
    dog.makeSound();

    std::cout << "---------------------" << std::endl;

    Cat cat;
    cat.makeSound();

    std::cout << "---------------------" << std::endl;

    WrongAnimal wrongAnimal;
    wrongAnimal.makeSound();

    std::cout << "---------------------" << std::endl;

    WrongCat wrongCat;
    wrongCat.makeSound();

    return 0;
}
