/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:03:21 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/01 15:58:14 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

void	signal_handler(int sig, struct __siginfo *info, void *context)
{
	static int	bit;
	static char	c;

	(void)context;
	if (sig == SIGUSR1)
		c |= 1 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = '\0';
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	(void)av;
	if (ac == 1)
	{
		pid = getpid();
		ft_printf("PID number: %d\n", pid);
		ft_printf("Pending message to print...\n");
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
		return (0);
	}
	else
	{
		ft_printf("No arguments allowed\n");
		ft_printf("Stopping process\n");
		return (0);
	}
}
