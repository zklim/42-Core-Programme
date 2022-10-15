/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:12:46 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/16 00:12:48 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!dst && dstsize == 0)
		return (0);
	j = ft_strlen(dst);
	if (dstsize <= j)
		return (dstsize + ft_strlen(src));
	while (src[i] && j < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}

/*int	main(void)
{
	int i;
	char a[20] = "Hello";
	char b[20] = "World";

	i = ft_strlcat(a, b, 9);
	printf("%d,%s\n", i, a);
}*/