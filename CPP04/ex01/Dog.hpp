/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:14:07 by zhlim             #+#    #+#             */
/*   Updated: 2023/10/30 20:58:40 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

// public derive makes Animal members accessible
class Dog: public Animal {

	private:
		Brain	*brain;
	
	public:
		Dog();
		~Dog();
		
		void	makeSound() const;
		Brain	&getBrain() const;
		Dog		&operator=(Dog &rhs);
};