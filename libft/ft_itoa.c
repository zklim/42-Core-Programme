/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:58:27 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/05 17:20:53 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;

	count = ft_count(n);
	str = (char *)malloc(sizeof(*str) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	while (n)
	{
		if (n < 0)
		{
			str[0] = '-';
			str[count - 1] = -(n % 10) + '0';
			n /= 10;
			count--;
		}
		else
		{
			str[count - 1] = n % 10 + '0';
			n /= 10;
			count--;
		}
	}
	return (str);
}

/*int	main(void)
{
	char *a;

	a = ft_itoa(0x80000000);
	printf("%s\n", a);
}*/