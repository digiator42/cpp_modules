/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:11 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/28 05:29:22 by ahassan          ###   ########.fr       */
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
    // Animal *animal[] = {
    //     new Dog("Wolf"),
    //     new Dog("Wolf"),
    //     new Dog("Wolf"),
    //     new Dog("Wolf"),
    //     new Cat("Miaw"),
    //     new Cat("Miaw"),
    //     new Cat("Miaw"),
    //     new Cat("Miaw"),
    // };
    // for (int i = 0; i < 8; i++)
    //     animal[i]->makeSound();
    // for (int i = 0; i < 8; i++)
    //     delete animal[i];

    /*testing brain getters && setters*/
    Cat cat("Bella");
    Dog dog("Oliver");
    cat.setIdea(0, "I am thinking to Miaw while homan is sleeping");
    dog.setIdea(0, "I am thinking to Bark as well");
    cat.setIdea(1, "Should i Miaw");
    dog.setIdea(1, "Should i Bark");
    cat.setIdea(2, "But homan is tired :(");
    dog.setIdea(2, "Yeah, he is");
    cat.setIdea(3, "I Can't, I am gonna MIAAAAAAAAWWWW");
    dog.setIdea(3, "You Miaw, I Baaaaaaaark");
    
    for (int i = 0; i < 4; i++){
        std::cout << cat.getType() << ": " << cat.getIdea(i);
        std::cout << dog.getType() << ": " << dog.getIdea(i);
    }

    return 0;
}
