/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim < zhlim@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:59:39 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/03 19:04:57 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

//memmove uses tmp array to preserve src data.
//so it will be "safe" when dst and src overlap.
void	ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*s;
	char		*d;
	char		tmp[1000];

	s = src;
	d = dst;
	i = 0;
	while (s[i] && i < len)
	{
		tmp[i] = s[i];
		i++;
	}
	i = 0;
	while (tmp[i] && i < len)
	{
		d[i] = tmp[i];
		i++;
	}
}
