/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:53:14 by zhlim             #+#    #+#             */
/*   Updated: 2023/11/01 02:51:51 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
	// correct implementations, dynamic dispatch
	std::cout << "================Testing default================" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;
	std::cout << std::endl;

	std::cout << "================Testing wrong implementations================" << std::endl;
	const WrongAnimal* a = new WrongAnimal();
	const WrongAnimal* c = new WrongCat();
	std::cout << a->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	a->makeSound(); 
	std::cout << GREY << "Test: should output the cat sound! But no" << RESET << std::endl;
	c->makeSound(); //should output the cat sound! But no
	delete a;
	delete c;
	std::cout << std::endl;

	std::cout << "================Testing non pointer class creations================" << std::endl;
	Animal	aa;
	Cat		cc;
	std::cout << aa.getType() << " " << std::endl;
	std::cout << cc.getType() << " " << std::endl;
	aa.makeSound(); 
	cc.makeSound();

	system("leaks -q main");
	return 0;
}