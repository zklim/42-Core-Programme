/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:46:24 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/14 14:44:17 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		total;
	int		i;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	total = count * size;
	i = 0;
	ptr = (void *)malloc(total);
	if (!ptr)
		return (NULL);
	while (total--)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
