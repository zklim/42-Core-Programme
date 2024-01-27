/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:36:29 by zhlim             #+#    #+#             */
/*   Updated: 2023/10/31 11:33:15 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
	this->type = "Undefined";
	std::cout << "Created an Animal of " << this->type << GREY << " Constructor" << RESET << std::endl;
}

AAnimal::AAnimal(std::string type): type(type) {
	std::cout << "Created an Animal of " << this->type << GREY << " Constructor" << RESET << std::endl;
}

AAnimal::AAnimal(AAnimal &rhs) {
	this->type = rhs.getType();
}

AAnimal::~AAnimal() {
	std::cout << "Destroyed an Animal of " << this->type << GREY << " Destructor" << RESET << std::endl;
}

std::string	AAnimal::getType() const {
	return this->type;
}

AAnimal		&AAnimal::operator=(AAnimal &rhs) {
	this->type = rhs.getType();
	return *this;
}