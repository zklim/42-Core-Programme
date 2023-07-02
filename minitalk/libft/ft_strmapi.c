/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:27:19 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/12 15:32:28 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_strlen(char const *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		count;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	count = ft_strlen(s);
	res = (char *)malloc(sizeof(*res) * (count + 1));
	if (!res)
	{
		return (NULL);
	}
	while (s[i])
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*static char    f(unsigned int i, char c)
{
    (void) i;
    c -= 32;
    return (c);
}

int	main(void)
{
    char    *a;
    
    a = ft_strmapi("helloworld", f);
    printf("%s\n", a);
}*/