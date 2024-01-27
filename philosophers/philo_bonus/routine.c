/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:00:12 by zhlim             #+#    #+#             */
/*   Updated: 2023/09/13 15:32:44 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_exit(t_philo *philo)
{
	pthread_mutex_destroy(&philo->lock);
	exit(0);
}

void	take_fork(t_philo *philo)
{
	sem_wait(philo->states->sem.forks);
	pthread_mutex_lock(&philo->lock);
	philo->now = get_timestamp() - philo->states->start;
	pthread_mutex_unlock(&philo->lock);
	if (is_dead(philo))
	{
		sem_post(philo->states->sem.forks);
		sem_close(philo->states->sem.forks);
		ft_exit(philo);
	}
	ft_print(philo, FORK_LEFT);
	sem_wait(philo->states->sem.forks);
	pthread_mutex_lock(&philo->lock);
	philo->now = get_timestamp() - philo->states->start;
	pthread_mutex_unlock(&philo->lock);
	if (is_dead(philo))
	{
		sem_post(philo->states->sem.forks);
		sem_post(philo->states->sem.forks);
		sem_close(philo->states->sem.forks);
		ft_exit(philo);
	}
	ft_print(philo, FORK_RIGHT);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	philo->last_eat = get_timestamp() - philo->states->start;
	pthread_mutex_unlock(&philo->lock);
	if (is_dead(philo))
		ft_exit(philo);
	ft_print(philo, EAT);
	pthread_mutex_lock(&philo->lock);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->lock);
	ft_usleep(philo->states->time_to_eat);
	sem_post(philo->states->sem.forks);
	sem_post(philo->states->sem.forks);
}

int	sleep_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	philo->now = get_timestamp() - philo->states->start;
	pthread_mutex_unlock(&philo->lock);
	if (is_dead(philo))
		ft_exit(philo);
	ft_print(philo, SLEEP);
	ft_usleep(philo->states->time_to_sleep);
	pthread_mutex_lock(&philo->lock);
	philo->now = get_timestamp() - philo->states->start;
	pthread_mutex_unlock(&philo->lock);
	if (is_dead(philo))
		ft_exit(philo);
	ft_print(philo, THINK);
	return (0);
}

void	routine(t_philo *philo)
{
	if (philo->states->times_must_eat > 0)
		sem_wait(philo->states->sem.eats);
	sem_wait(philo->states->sem.dead);
	pthread_mutex_init(&philo->lock, NULL);
	pthread_create(&philo->monitor, NULL, monitor, philo);
	pthread_detach(philo->monitor);
	while (1)
	{
		take_fork(philo);
		eat(philo);
		sleep_think(philo);
	}
}
