/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:52:18 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/05 16:52:56 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	dest = (char *)malloc(sizeof(*s1) * i);
	if (!dest)
		return (0);
	else
	{
		i = 0;
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}

/*int main(void)
{
    char    *a;

    a = ft_strdup("HelloWorld!");
    printf("%s\n", a);
}*/