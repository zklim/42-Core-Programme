/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:50:02 by zhlim             #+#    #+#             */
/*   Updated: 2023/09/13 15:22:01 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_states(char **av, t_states *states)
{
	states->number_philos = ft_atoi(*av);
	states->time_to_die = ft_atoi(*(av + 1));
	states->time_to_eat = ft_atoi(*(av + 2));
	states->time_to_sleep = ft_atoi(*(av + 3));
	if (*(av + 4))
		states->times_must_eat = ft_atoi(*(av + 4));
	else
		states->times_must_eat = -1;
	states->someone_died = 0;
	states->finish_eat = 0;
	pthread_mutex_init(&states->lock, NULL);
	pthread_mutex_init(&states->print, NULL);
}

int	invalidate(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ac < 5 || ac > 6)
		return (1);
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] < '0' && av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_dead2(t_philo *philo, t_local_p *local)
{
	pthread_mutex_lock(&philo->states->lock);
	if (philo->eat_count == local->times_must_eat
		&& !philo->recorded)
	{
		philo->states->finish_eat++;
		philo->recorded = 1;
		if (philo->states->finish_eat == local->number_philos)
		{
			philo->states->someone_died = 1;
			pthread_mutex_unlock(&philo->states->lock);
			return (1);
		}
	}
	else if (local->now - philo->last_eat
		>= local->time_to_die)
	{
		philo->states->someone_died = 1;
		ft_print(philo, DIED, local->now);
		pthread_mutex_unlock(&philo->states->lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->states->lock);
	return (0);
}

void	check_dead(t_states *states)
{
	t_local_p	local;

	local.i = 0;
	pthread_mutex_lock(&states->lock);
	local.times_must_eat = states->times_must_eat;
	local.time_to_die = states->time_to_die;
	local.number_philos = states->number_philos;
	pthread_mutex_unlock(&states->lock);
	while (local.i < states->number_philos)
	{
		local.now = get_timestamp() - states->start;
		if (check_dead2(&states->philos[local.i], &local))
			break ;
		local.i++;
		if (local.i == states->number_philos)
			local.i = 0;
		usleep(10);
	}
}

int	main(int ac, char **av)
{
	t_states	states;
	int			err;

	if (invalidate(ac, av + 1))
		return (1);
	init_states(av + 1, &states);
	if (create_philo(&states))
		return (1);
	err = create_forks(&states);
	if (err)
		return (err);
	err = create_threads(&states);
	if (err)
		return (err);
	check_dead(&states);
	err = ft_free(&states);
	if (err)
		return (err);
	return (0);
}
