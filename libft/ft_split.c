/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:10:17 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/05 16:57:39 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	word_count(char const *s, char c)
{
	int	count;

	count = 0;
	if (*s != c && *s >= 32 && *s <= 126)
		if (*s != c)
			count++;
	while (*s)
	{
		if (*(s - 1) == c && *s >= 32 && *s <= 126)
			count++;
		s++;
	}
	return (count);
}

static char	*ft_strdup(const char *s1, char c)
{
	char	*dest;
	int		i;

	i = 0;
	while (s1[i] != c)
		i++;
	dest = (char *)malloc(sizeof(*s1) * i);
	if (!dest)
		return (0);
	else
	{
		i = 0;
		while (s1[i] != c)
		{
			dest[i] = s1[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;
	int		i;

	i = 0;
	count = word_count(s, c);
	arr = (char **)malloc(sizeof(*arr) * (count + 1));
	if (!arr)
		return (NULL);
	if (*s != c && *s >= 32 && *s <= 126)
	{
		arr[i] = ft_strdup(s, c);
		i++;
	}
	while (*s)
	{
		if (*(s - 1) == c && *s >= 32 && *s <= 126)
		{
			arr[i] = ft_strdup(s, c);
			i++;
		}
		s++;
	}
	arr[i] = NULL;
	return (arr);
}

/*int main(void)
{
    int     i;
    char    **a;
    
    a = ft_split("Hello-World-How-Are-You?", '-');
    for (i = 0; i < 5; i++)
        printf("%s\n", a[i]);
}*/