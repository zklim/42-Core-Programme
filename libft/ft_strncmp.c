/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:24:42 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/04 23:17:17 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
		i++;
	if (i < n)
		return (s1[i] - s2[i]);
	else
		return (0);
}

/* int main(void)
{
	char	a[];
	char	b[];

	a[] = "Hello";
	b[] = "Helio";
	printf("%d\n", strncmp(a, b, 4));
}*/