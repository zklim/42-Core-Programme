/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:32:30 by zhlim             #+#    #+#             */
/*   Updated: 2023/10/31 11:25:46 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->type = "Undefined";
	std::cout << "Created an Animal of " << this->type << GREY << " Constructor" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): type(type) {
	std::cout << "Created an Animal of " << this->type << GREY << " Constructor" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destroyed an Animal of " << this->type << GREY << " Destructor" << RESET << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << this->type << " couldn't make any sound" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return this->type;
}