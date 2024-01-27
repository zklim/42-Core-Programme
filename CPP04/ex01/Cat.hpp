/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:14:05 by zhlim             #+#    #+#             */
/*   Updated: 2023/10/31 10:16:57 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

// public derive makes Animal members accessible
class Cat: public Animal {
	
	private:
		Brain	*brain;
	
	public:
		Cat();
		~Cat();

		void	makeSound() const;
		Brain	&getBrain() const;
		Cat		&operator=(Cat &rhs);
};