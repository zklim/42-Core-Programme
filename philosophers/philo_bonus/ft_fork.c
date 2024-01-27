/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:20:36 by zhlim             #+#    #+#             */
/*   Updated: 2023/09/12 18:42:07 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sem_eat(t_states *states)
{
	int			i;

	i = 0;
	while (i < states->number_philos)
	{
		sem_wait(states->sem.eats);
		i++;
	}
	sem_post(states->sem.dead);
	exit(0);
}

void	parenting(t_states *states, int i)
{
	usleep(800);
	if (states->times_must_eat > 0)
	{
		states->sem_eat = fork();
		if (states->sem_eat == 0)
			sem_eat(states);
	}
	sem_wait(states->sem.dead);
	while (i < states->number_philos)
	{
		kill(states->philos[i].pid, SIGTERM);
		waitpid(states->philos[i].pid, NULL, 0);
		i++;
	}
	if (states->times_must_eat > 0)
	{
		kill(states->sem_eat, SIGTERM);
		waitpid(states->sem_eat, NULL, 0);
	}
}

void	ft_fork(t_states *states)
{
	int	i;

	i = 0;
	states->start = get_timestamp();
	while (i < states->number_philos)
	{
		states->philos[i].id = i + 1;
		states->philos[i].pid = fork();
		if (states->philos[i].pid == 0)
			routine(&states->philos[i]);
		i++;
		usleep(50);
	}
	i = 0;
	if (states->philos[i].pid != 0)
		parenting(states, i);
}

// void	ft_fork(t_states *states)
// {
// 	(void)states;
// 	ft_sem_unlink();
// }