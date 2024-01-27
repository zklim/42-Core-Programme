/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:20:36 by zhlim             #+#    #+#             */
/*   Updated: 2023/09/12 01:09:59 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo, t_local_c *local)
{
	pthread_mutex_lock(&philo->fork.left);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(&philo->fork.left);
		return (1);
	}
	local->now = get_timestamp() - local->start;
	ft_print(philo, FORK_LEFT, local->now);
	if (local->number_philos == 1)
	{
		while (1)
			if (is_dead(philo))
				return (1);
	}
	pthread_mutex_lock(philo->fork.right);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->fork.right);
		pthread_mutex_unlock(&philo->fork.left);
		return (1);
	}
	local->now = get_timestamp() - local->start;
	ft_print(philo, FORK_RIGHT, local->now);
	return (0);
}

int	eat(t_philo *philo, t_local_c *local)
{
	if (is_dead(philo))
		return (1);
	pthread_mutex_lock(&philo->states->lock);
	philo->last_eat = get_timestamp() - local->start;
	ft_print(philo, EAT, local->now);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->states->lock);
	ft_usleep(local->eat_time);
	pthread_mutex_unlock(philo->fork.right);
	pthread_mutex_unlock(&philo->fork.left);
	return (0);
}

int	sleep_think(t_philo *philo, t_local_c *local)
{
	if (is_dead(philo))
		return (1);
	local->now = get_timestamp() - local->start;
	ft_print(philo, SLEEP, local->now);
	ft_usleep(local->sleep_time);
	if (is_dead(philo))
		return (1);
	local->now = get_timestamp() - local->start;
	ft_print(philo, THINK, local->now);
	return (0);
}

void	*routine(void *args)
{
	t_philo		*philo;
	t_local_c	local;

	philo = (t_philo *)args;
	local.now = 0;
	if (!(philo->id % 2))
		usleep(100);
	pthread_mutex_lock(&philo->states->lock);
	local.eat_time = philo->states->time_to_eat;
	local.sleep_time = philo->states->time_to_sleep;
	local.start = philo->states->start;
	local.number_philos = philo->states->number_philos;
	pthread_mutex_unlock(&philo->states->lock);
	while (1)
	{
		if (take_fork(philo, &local))
			break ;
		if (eat(philo, &local))
			break ;
		if (sleep_think(philo, &local))
			break ;
	}
	return (NULL);
}

int	create_threads(t_states *states)
{
	int	i;
	int	err;

	i = 0;
	states->start = get_timestamp();
	while (i < states->number_philos)
	{
		states->philos[i].id = i + 1;
		err = pthread_create(&states->philos[i].thread, NULL, routine,
				&states->philos[i]);
		if (err)
			return (err);
		i++;
		usleep(25);
	}
	return (0);
}
