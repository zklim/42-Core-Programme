/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:53:14 by zhlim             #+#    #+#             */
/*   Updated: 2023/11/01 02:47:44 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
	std::cout << "===============Test default===============" << std::endl;
	const AAnimal	*j = new Dog();
	const AAnimal	*i = new Cat();

	delete j; // should not create a leak
	delete i;
	std::cout << std::endl;

	std::cout << "===============Test arrays===============" << std::endl;
	AAnimal			*animals[10];

	for (int i = 0; i < 5; i++)
		animals[i] = new Cat();
	for (int i = 5; i < 10; i++)
		animals[i] = new Dog();
	for (int i = 0; i < 10; i++)
		delete animals[i];
	std::cout << std::endl;

	std::cout << "===============Test shallow copy===============" << std::endl;
	WrongCat		*k = new WrongCat();
	WrongCat		*l = new WrongCat(*k);

	k->getBrain().addIdea(0, "Test idea");
	std::cout << l->getBrain().getIdea(0) << GREY << " Test: Print l" << RESET << std::endl;
	k->getBrain().addIdea(0, "Shallow copy");
	std::cout << l->getBrain().getIdea(0) << GREY << " Test: Print l after changing k" << RESET << std::endl;
	delete k;
	std::cout << std::endl;

	std::cout << "===============Test deep copy===============" << std::endl;
	Cat		*m = new Cat();
	Cat		*n = new Cat();

	m->getBrain().addIdea(0, "Test idea");
	*n = *m;
	std::cout << n->getBrain().getIdea(0) << GREY << " Test: Print n" << RESET << std::endl;
	std::cout << m->getBrain().getIdea(0) << GREY << " Test: Print m" << RESET << std::endl;
	m->getBrain().addIdea(0, "Deep copy");
	std::cout << n->getBrain().getIdea(0) << GREY << " Test: Print n after changing m" << RESET << std::endl;
	std::cout << m->getBrain().getIdea(0) << GREY << " Test: Print m again" << RESET << std::endl;
	delete m;
	delete n;
	std::cout << std::endl;

	// std::cout << "===============Test Abstract===============" << std::endl;
	// AAnimal			abstract;
	// AWrongAnimal	aabstract;

	// system("leaks -q main"); // Check for memory leaks
	return 0;
}