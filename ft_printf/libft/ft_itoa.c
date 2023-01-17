/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:58:27 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/12 15:28:09 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*op_alloc(int n, char *str, int count)
{
	if (n < 0)
	{
		str[0] = '-';
		while (n)
		{
			str[count - 1] = -(n % 10) + '0';
			n /= 10;
			count--;
		}
	}
	else if (n == 0)
		str[0] = '0';
	else
	{
		while (n)
		{
			str[count - 1] = n % 10 + '0';
			n /= 10;
			count--;
		}
	}
	return (str);
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
	return (op_alloc(n, str, count));
}

/*int	main(void)
{
	char *a;

	a = ft_itoa(0x80000000);
	printf("%s\n", a);
}*/