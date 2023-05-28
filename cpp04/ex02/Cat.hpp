/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:04 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/28 04:56:26 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain *brain;
public:
    Cat();
    Cat(const std::string &name);
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    ~Cat();
    std::string getIdea(int index) const;
    void setIdea(int index, const std::string& idea);

    void makeSound() const;
};

#endif
