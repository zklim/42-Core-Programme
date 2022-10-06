/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:08:38 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/05 13:32:09 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)(haystack));
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] != '\0')
		{
			if (haystack[i + j] == needle[j] && (i + j) < len)
			{
				j++;
			}
			else
				break ;
		}
		if (needle[j] == '\0')
		{
			return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}

/*int main(void)
{
    char    a[] = "HelloWorld!";
    char    b[] = "Wor";
    
    printf("%s\n", ft_strnstr(a, b, 7));
}*/