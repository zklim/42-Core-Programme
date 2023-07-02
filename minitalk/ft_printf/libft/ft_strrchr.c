/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:11:57 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/15 15:23:31 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = NULL;
	while (*s || (char)c == '\0')
	{
		if (*s == (char)c)
		{
			res = (char *)s;
			if ((char)c == '\0')
				return (res);
		}
		s++;
	}
	return (res);
}

/*int	main(void)
{
	char a[] = "HelloWorld!";
	char *b;

	b = ft_strrchr(a, '\0');
	printf("%s\n", b);
}*/