/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:51:00 by zhlim             #+#    #+#             */
/*   Updated: 2023/10/31 11:30:36 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): AAnimal("Cat") {
	this->brain = new Brain();
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Bye miaw miaw" << GREY << " Destructor" << RESET << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}

Brain	&Cat::getBrain() const {
	return *this->brain;
}

Cat		&Cat::operator=(Cat &rhs) {
	if (this != &rhs) {
		delete this->brain;
		this->brain = new Brain(rhs.getBrain());
		AAnimal::operator=(rhs);
	}
	return *this;
};