/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 05:56:04 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/28 17:42:58 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat(const std::string &name);
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    ~Cat();
    std::string getType() const;
    void makeSound() const;
};

#endif
