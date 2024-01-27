/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:06:20 by zhlim             #+#    #+#             */
/*   Updated: 2023/10/31 11:29:24 by zhlim            ###   ########.fr       */
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

class AAnimal {
	
	protected:
		std::string	type;

	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(AAnimal &rhs);
		virtual ~AAnimal();

		virtual void	makeSound() const = 0; // Pure virtual function to make this as abstract class / interface
		std::string		getType() const;
		AAnimal			&operator=(AAnimal &rhs);
};