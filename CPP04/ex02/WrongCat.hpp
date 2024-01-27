/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:14:05 by zhlim             #+#    #+#             */
/*   Updated: 2023/11/01 02:34:53 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AWrongAnimal.hpp"
# include "Brain.hpp"

// public derive makes Animal members accessible
class WrongCat: public AWrongAnimal {
	
	private:
		Brain	*brain;

	public:
		WrongCat();
		~WrongCat();

		void		makeSound() const;
		Brain		&getBrain() const;
};