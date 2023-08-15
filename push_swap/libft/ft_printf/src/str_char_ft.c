/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_char_ft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:18:14 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/25 14:44:55 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c, int *i)
{
	write(1, &c, 1);
	(*i)++;
}

void	put_char(va_list *ap, int *i)
{
	char	c;

	c = va_arg(*ap, int);
	ft_putchar(c, i);
}

void	put_str(va_list *ap, int *i)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (str)
	{
		while (*str)
		{
			write(1, &(*str), 1);
			str++;
			(*i)++;
		}
	}
	else if (!str)
	{
		write(1, "(null)", 6);
		(*i) += 6;
	}
}
