/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:11 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/25 07:10:08 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    // Animal animal;
    // animal.makeSound();

    // std::cout << "---------------------" << std::endl;

    // Dog dog;
    // dog.makeSound();

    // std::cout << "---------------------" << std::endl;

    // Cat cat;
    // cat.makeSound();

    // std::cout << "---------------------" << std::endl;

    // WrongAnimal wrongAnimal;
    // wrongAnimal.makeSound();

    // std::cout << "---------------------" << std::endl;

    // WrongCat wrongCat; // still calling wrongCat makeSound() due to the derived class will hide the function in the base class instead of overriding it. This behavior is called function hiding
    // wrongCat.makeSound();

    // achieving polymorphic behavior 
    const WrongAnimal* wrong_cat = new WrongCat();
	const WrongAnimal* wrong_animal = new WrongAnimal();

	std::cout << std::endl;

	wrong_cat->makeSound();

	wrong_animal->makeSound();

	std::cout << std::endl;

	delete wrong_cat;
	delete wrong_animal;

	const WrongAnimal* wrongAnimal = new WrongCat(); //polymorphic, base takes derived class as pointer and acheiving same result of virtual function use

	std::cout << std::endl;

	wrong_animal->makeSound();

	std::cout << std::endl;

	delete wrongAnimal;

    return 0;
}
