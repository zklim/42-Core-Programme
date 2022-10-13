/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:51:02 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/13 17:42:02 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*_s;

	_s = (char *)s;
	while (n)
	{
		if (*_s == (char)c)
			return (_s);
		_s++;
		n--;
	}
	return (NULL);
}

/*int	main(void)
{
	char	a[] = "HelloWorld!";
	char	*b;

	b = ft_memchr(a, 'r', 8);
	printf("%s\n%s\n", b, a);
}*/