/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:36:26 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/15 18:03:20 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	nbr_ft(const char *str, int sign)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str++ - '0');
		i++;
		if (i >= 20 && sign > 0)
			return (-1);
		else if (i >= 20 && sign < 0)
			return (0);
	}
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return (nbr_ft(str, sign));
}

/*int	main(void)
{
	printf("%d\n", ft_atoi("  -2147483648"));
}*/