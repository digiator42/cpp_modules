/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:11 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/28 18:44:22 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

    // achieving polymorphic behavior 

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete j;//should not create a leak
    delete i;
    delete meta;

    const WrongAnimal* wrong_cat = new WrongCat();
	const WrongAnimal* wrong_animal = new WrongAnimal();

	std::cout << "-----------------" << std::endl;

	wrong_cat->makeSound();

	wrong_animal->makeSound();

	std::cout << "-----------------" << std::endl;

	delete wrong_cat;
	delete wrong_animal;

	const WrongAnimal* wrongAnimal = new WrongCat(); //polymorphic, base takes derived class as pointer and acheiving same result of virtual function use
	wrongAnimal->makeSound();
	delete wrongAnimal;

    return 0;
}
