/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:07:24 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/05 18:31:03 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 1 << 31)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar('8', fd);
	}
	else if (n < 0)
	{
		ft_putchar('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar('0' + (n % 10), fd);
	}
}

/*int	main(void)
{
	ft_putnbr_fd(0x80000000, 1);
}*/