/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:12:46 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/11 15:28:59 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	dc;
	size_t	sc;

	i = 0;
	dc = 0;
	sc = 0;
	while (src[sc])
		sc++;
	if (dstsize == 0)
		return (sc);
	while (dst[dc])
		dc++;
	if (dstsize <= dc)
		return (sc + dstsize);
	while (src[i] && dc + i < dstsize - 1)
	{
		dst[dc + i] = src[i];
		i++;
	}
	dst[dc + i] = '\0';
	return (dc + sc);
}

/*int	main(void)
{
	int i;
	char a[20] = "Hello";
	char b[20] = "World";

	i = ft_strlcat(a, b, 9);
	printf("%d,%s\n", i, a);
}*/