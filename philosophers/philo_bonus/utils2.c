/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:53:14 by zhlim             #+#    #+#             */
/*   Updated: 2023/09/12 18:42:18 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	if (philo->now - philo->last_eat >= philo->states->time_to_die)
	{
		pthread_mutex_unlock(&philo->lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->lock);
	return (0);
}

void	ft_sem_unlink(void)
{
	sem_unlink("gib_fork");
	sem_unlink("dead");
	sem_unlink("eat");
	sem_unlink("print");
}

void	ft_sem_close(t_states *states)
{
	sem_close(states->sem.forks);
	sem_close(states->sem.dead);
	sem_close(states->sem.eats);
}

int	ft_free(t_states *states)
{
	ft_sem_close(states);
	ft_sem_unlink();
	free(states->philos);
	return (0);
}
