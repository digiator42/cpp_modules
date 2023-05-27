/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:11 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/27 20:29:02 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    /*-----Basic testing------*/
    
    // Dog dog("Wolf");
    // Dog dog2(dog);
    // dog.makeSound();
    // dog2.makeSound();
    // std::cout << "-----------------\n";
    // Cat cat("Wolf");
    // Cat cat2(cat);
    // cat.makeSound();
    // cat2.makeSound();
    // std::cout << "-----------------\n";
    // cat2 = cat;
    // cat.makeSound();
    // cat2.makeSound();
    // std::cout << "-----------------\n";
    // Animal a; // error 'Animal' is an abstract class
    Animal *animal[] = {
        new Dog("Wolf"),
        new Dog("Wolf"),
        new Dog("Wolf"),
        new Dog("Wolf"),
        new Cat("Miaw"),
        new Cat("Miaw"),
        new Cat("Miaw"),
        new Cat("Miaw"),
    };
    for (int i = 0; i < 8; i++)
        animal[i]->makeSound();
    for (int i = 0; i < 8; i++)
        delete animal[i];
    return 0;
}
