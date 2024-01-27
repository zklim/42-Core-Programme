/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:03:49 by zhlim             #+#    #+#             */
/*   Updated: 2023/09/12 18:42:45 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		pthread_mutex_lock(&philo->lock);
		philo->now = get_timestamp() - philo->states->start;
		if (philo->eat_count == philo->states->times_must_eat)
		{
			sem_post(philo->states->sem.eats);
			pthread_mutex_unlock(&philo->lock);
			break ;
		}
		else if (philo->now - philo->last_eat >= philo->states->time_to_die)
		{
			sem_wait(philo->states->sem.print);
			printf(YELLOW "%d %d died\n" RESET, philo->now, philo->id);
			sem_post(philo->states->sem.dead);
			pthread_mutex_unlock(&philo->lock);
			break ;
		}
		pthread_mutex_unlock(&philo->lock);
		usleep(25);
	}
	return (NULL);
}
