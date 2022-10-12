/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:10:17 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/12 15:31:59 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	word_count(char const *s, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			i++;
			trigger = 1;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (i);
}

static char	*ft_dup(const char *s1, int start, int finish)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(sizeof(*s1) * (finish - start + 1));
	if (!res)
		return (0);
	i = 0;
	while (start < finish)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}

static char	**op_alloc(char **arr, char const *s, char c)
{
	size_t	i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			arr[j++] = ft_dup(s, start, i);
			start = -1;
		}
		i++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(*arr) * (word_count(s, c) + 1));
	if (!arr)
		return (NULL);
	return (op_alloc(arr, s, c));
}

/*int	main(void)
{
	int i;
	char **a;

	a = ft_split("Hello-World-How-Are-You", '-');
	for (i = 0; i < 5; i++)
		printf("%s\n", a[i]);
}*/