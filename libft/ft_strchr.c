/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:31:17 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/10 14:56:36 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s || c == '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

/*int	main(void)
{
	char a[] = "HelloWorld!";
	char *b;

	b = ft_strchr(a, 'o');
	printf("%s\n", b);
}*/