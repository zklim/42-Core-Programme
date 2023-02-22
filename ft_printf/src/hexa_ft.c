/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:22:34 by zhlim             #+#    #+#             */
/*   Updated: 2023/02/22 13:37:49 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putnub_hexa(size_t nb, int *i)
{
	if (nb >= 16)
	{
		ft_putnub_hexa(nb / 16, i);
		ft_putnub_hexa(nb % 16, i);
	}
	else if (nb < 10)
		ft_putchar(('0' + nb), i);
	else
		ft_putchar(('a' + nb % 10), i);
}

void	put_add(va_list *ap, int *i)
{
	size_t	add;

	add = va_arg(*ap, size_t);
	write(1, "0x", 2);
	(*i) += 2;
	ft_putnub_hexa(add, i);
}

void	put_hexa(va_list *ap, int *i)
{
	unsigned int	nb;

	nb = va_arg(*ap, unsigned int);
	ft_putnub_hexa(nb, i);
}

void	ft_putnub_hexa_upper(size_t nb, int *i)
{
	if (nb >= 16)
	{
		ft_putnub_hexa_upper(nb / 16, i);
		ft_putnub_hexa_upper(nb % 16, i);
	}
	else if (nb < 10)
		ft_putchar(('0' + nb), i);
	else
		ft_putchar(('A' + nb % 10), i);
}

void	put_hexa_upper(va_list *ap, int *i)
{
	unsigned int	nb;

	nb = va_arg(*ap, unsigned int);
	ft_putnub_hexa_upper(nb, i);
}
