/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 05:14:26 by ahassan           #+#    #+#             */
/*   Updated: 2023/05/28 04:32:40 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain& Brain::operator=(const Brain &other) 
{
	std::cout << "Brain copy assignment constructor called" << std::endl;
	if(this != &other){
       for(int i = 0; i < 100 ;i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
		return ideas[index] + "\n";
		
	return "Exception: Invalid Index\n";
}
void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100){
        ideas[index] = idea;
		return ;	
	}
    std::cout << "Exception: Invalid Index\n";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}