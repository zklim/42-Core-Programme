/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:57:13 by zhlim             #+#    #+#             */
/*   Updated: 2023/11/01 02:49:48 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Some brilliant idea";
	std::cout << "New brain!" << GREY << " Constructor" << RESET << std::endl;
}

Brain::Brain(Brain &rhs) {
	std::string	*ideas = rhs.getIdeas();
	
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ideas[i];
}

Brain::~Brain() {
	std::cout << "Thrown the brain away" << GREY << " Destructor" << RESET << std::endl;
}

void		Brain::addIdea(int i, std::string idea) {
	this->_ideas[i] = idea;
}

std::string	Brain::getIdea(int i) {
	return this->_ideas[i];
}

std::string	*Brain::getIdeas() {
	return this->_ideas;
}

Brain		&Brain::operator=(Brain &rhs) {
	std::string	*ideas;

	if (this != &rhs) {
		ideas = rhs.getIdeas();
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = ideas[i];
	}
	return *this;
}