/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nub_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:23:47 by zhlim             #+#    #+#             */
/*   Updated: 2023/01/05 14:24:31 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putnub(int nb, int *i)
{
	if (nb == 1 << 31)
	{
		ft_putnub(nb / 10, i);
		ft_putchar('8', i);
	}
	else if (nb < 0)
	{
		ft_putchar('-', i);
		ft_putnub(-nb, i);
	}
	else if (nb >= 10)
	{
		ft_putnub(nb / 10, i);
		ft_putnub(nb % 10, i);
	}
	else
		ft_putchar(('0' + nb), i);
}

void	put_nub(va_list *ap, int *i)
{
	int	nb;

	nb = va_arg(*ap, int);
	ft_putnub(nb, i);
}

void	ft_putunub(unsigned int nb, int *i)
{
	if (nb >= 10)
	{
		ft_putunub(nb / 10, i);
		ft_putunub(nb % 10, i);
	}
	else
		ft_putchar(('0' + nb), i);
}

void	put_unub(va_list *ap, int *i)
{
	unsigned int	nb;

	nb = va_arg(*ap, unsigned int);
	ft_putunub(nb, i);
}
