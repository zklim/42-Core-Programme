/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:26:36 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/05 13:01:25 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//memcmp does not terminate by null.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*_s1;
	char	*_s2;

	_s1 = (char *)s1;
	_s2 = (char *)s2;
	i = 0;
	while (_s1[i] == _s2[i] && i < n)
		i++;
	if (i < n)
		return (_s1[i] - _s2[i]);
	else
		return (0);
}

/*int	main(void)
{
	char a[] = "";
	char b[] = "";

	printf("%d\n", ft_memcmp(a, b, 2));
}*/