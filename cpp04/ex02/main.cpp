/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:11 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/28 05:03:45 by ahassan          ###   ########.fr       */
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

    /*testing brain getters && setters*/
    Cat cat;
    cat.setIdea(0, "I am thinking to Miaw while homan is sleeping");
    cat.setIdea(1, "Should i Miaw");
    cat.setIdea(2, "But homan is tired :(");
    cat.setIdea(3, "I Can't, I am gonna MIAAAAAAAAWWWW");
    std::cout << cat.getIdea(3);
    std::cout << cat.getIdea(99);
    std::cout << cat.getIdea(300);
    std::cout << cat.getIdea(-1);
    Dog dog;
    dog.setIdea(0, "I am thinking to Bark as well");
    dog.setIdea(1, "Should i Bark");
    dog.setIdea(2, "Yeah, he is");
    dog.setIdea(3, "You Miaw, I Baaaaaaaark");
    std::cout << dog.getIdea(3);
    std::cout << dog.getIdea(99);
    std::cout << dog.getIdea(300);
    std::cout << dog.getIdea(-1);

    return 0;
}
