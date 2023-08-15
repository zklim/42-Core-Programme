/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:18:11 by zhlim             #+#    #+#             */
/*   Updated: 2023/02/22 13:37:00 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	check_flag(char c, va_list *ap, int *i)
{
	if (c == 'c')
		put_char(ap, i);
	if (c == 's')
		put_str(ap, i);
	if (c == 'p')
		put_add(ap, i);
	if (c == 'd' || c == 'i')
		put_nub(ap, i);
	if (c == 'u')
		put_unub(ap, i);
	if (c == 'x')
		put_hexa(ap, i);
	if (c == 'X')
		put_hexa_upper(ap, i);
	if (c == '%')
		ft_putchar('%', i);
}

int	print_str(const char *str, va_list *ap)
{
	int	i;

	i = 0;
	if (str)
	{
		while (*str)
		{
			if (*str == '%')
			{
				str++;
				check_flag(*str, ap, &i);
				str++;
			}
			else
			{
				write(1, &(*str), 1);
				str++;
				i++;
			}
		}
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, str);
	count = print_str(str, &ap);
	va_end(ap);
	return (count);
}
