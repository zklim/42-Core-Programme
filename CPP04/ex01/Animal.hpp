/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:06:20 by zhlim             #+#    #+#             */
/*   Updated: 2023/10/31 10:33:39 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

#define RESET "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class Animal {
	
	protected:
		std::string	type;

	public:
		Animal();
		Animal(std::string type);
		Animal(Animal &rhs);
		virtual ~Animal();

		virtual void	makeSound() const;
		std::string		getType() const;
		Animal			&operator=(Animal &rhs);
};