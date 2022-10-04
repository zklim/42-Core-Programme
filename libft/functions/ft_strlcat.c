/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:12:46 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/04 23:17:07 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	count1;
	size_t	count2;

	i = ft_strlen(dst);
	j = 0;
	count1 = ft_strlen(dst);
	count2 = ft_strlen(src);
	if (dstsize < 1)
		return (count2 + dstsize);
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (dstsize < count1)
		return (count2 + dstsize);
	else
		return (count1 + count2);
}

/*int main(void)
{
    int     i;
    char    a[10] = "Hello";
    char    b[] = "World";

    i = ft_strlcat(a, b, 8);
    printf("%d,%s\n", i, a);
}*/