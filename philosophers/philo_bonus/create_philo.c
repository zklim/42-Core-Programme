/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:26:28 by zhlim             #+#    #+#             */
/*   Updated: 2023/09/05 18:13:09 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_philo(t_philo *philo, t_states *states)
{
	philo->pid = 0;
	philo->id = 0;
	philo->states = states;
	philo->now = 0;
	philo->last_eat = 0;
	philo->eat_count = 0;
}

t_philo	*init_philos(t_states *states)
{
	int	i;

	i = 0;
	states->philos = malloc(sizeof(t_philo) * states->number_philos);
	if (!states->philos)
		return (NULL);
	while (i < states->number_philos)
	{
		init_philo(&states->philos[i], states);
		i++;
	}
	return (states->philos);
}

int	create_philo(t_states *states)
{
	if (!init_philos(states))
		return (1);
	return (0);
}
