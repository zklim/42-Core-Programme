/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:10:26 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/10 17:57:53 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_count(char const *s1, char const *set)
{
	int	i;
	int	c;

	c = 0;
	while (*s1)
	{
		i = 0;
		while (s1[i] == set[i])
			i++;
		if (set[i] == '\0')
			s1 += i;
		c++;
		s1++;
	}
	return (c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	char	*ptr;
	int		i;

	if (!s1)
		return (NULL);
	res = (char *)malloc(sizeof(*s1) * (ft_count(s1, set) + 1));
	if (!res)
		return (NULL);
	ptr = res;
	while (*s1)
	{
		i = 0;
		while (s1[i] == set[i])
			i++;
		if (set[i] == '\0')
			s1 += i;
		*res++ = *s1;
		s1++;
	}
	*res = '\0';
	return (ptr);
}

/*int main(void)
{
    printf("%s\n", ft_strtrim("How-*Are-*You", "-*"));
}*/