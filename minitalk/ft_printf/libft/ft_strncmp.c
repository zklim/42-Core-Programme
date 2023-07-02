/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:24:42 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/10 15:54:25 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*_s1;
	unsigned char	*_s2;

	_s1 = (unsigned char *)s1;
	_s2 = (unsigned char *)s2;
	i = 0;
	while (_s1[i] == _s2[i] && _s1[i] && _s2[i] && i < n)
		i++;
	if (i < n)
		return (_s1[i] - _s2[i]);
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