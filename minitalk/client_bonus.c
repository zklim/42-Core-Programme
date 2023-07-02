/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:17:54 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/01 16:13:21 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

void	acknowledges(int sig)
{
	static int	i;

	if (sig == SIGUSR1)
		ft_printf("Message Received: %d\n", ++i);
}

void	send_signal(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(120);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi(av[1]);
		signal(SIGUSR1, acknowledges);
		signal(SIGUSR2, acknowledges);
		while (av[2][i])
		{
			send_signal(pid, av[2][i]);
			i++;
		}
		send_signal(pid, '\n');
	}
	else
	{
		ft_printf("Wrong number of arguments\n");
		return (0);
	}
}
