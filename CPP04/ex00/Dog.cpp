/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:42:37 by zhlim             #+#    #+#             */
/*   Updated: 2023/10/31 11:22:33 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {}

Dog::~Dog() {
	std::cout << "Kill the dawg!" << GREY << " Destructor" << RESET << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Woof Woof!" << std::endl;
}