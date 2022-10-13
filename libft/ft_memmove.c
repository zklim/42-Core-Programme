/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:59:39 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/13 15:45:59 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < len)
	{
		if (dst > src)
			((char *)dst)[len - i - 1] = ((char *)src)[len - i - 1];
		else
			((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

/*int	main(void)
{
	char a[] = "Hello";
	char b[] = "World";
	char	*c;

	c = (char *)ft_memmove(a, b, 10);
	printf("%s\n", c);
	printf("%p\n%p\n", c, a);
}*/