/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:51:00 by zhlim             #+#    #+#             */
/*   Updated: 2023/10/31 11:25:53 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("Cat") {
	this->brain = new Brain();
}

WrongCat::~WrongCat() {
	delete this->brain;
	std::cout << "Bye miaw miaw" << GREY << " Destructor" << RESET << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}

Brain	&WrongCat::getBrain() const {
	return *this->brain;
}