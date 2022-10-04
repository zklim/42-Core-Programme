/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:51:02 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/04 19:22:05 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//memchr does not terminate with NULL.
//so it requires length to terminate.
void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n)
	{
		if (*str == c)
			return (str);
		str++;
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