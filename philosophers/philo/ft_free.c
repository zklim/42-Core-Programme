/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:16:06 by zhlim             #+#    #+#             */
/*   Updated: 2023/09/13 15:22:09 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_forks(t_states *states, int end)
{
	int	i;
	int	err;

	i = 0;
	while (i < end)
	{
		err = pthread_mutex_destroy(&states->philos[i].fork.left);
		if (err)
			return (err);
		i++;
	}
	return (0);
}

void	ft_join(t_states *states)
{
	int	i;
	int	err;

	i = 0;
	while (i < states->number_philos)
	{
		err = pthread_join(states->philos[i].thread, NULL);
		if (err)
			return ;
		i++;
		usleep(10);
	}
}

int	ft_free(t_states *states)
{
	int	err;

	ft_join(states);
	err = pthread_mutex_destroy(&states->lock);
	err = pthread_mutex_destroy(&states->print);
	if (err)
		return (err);
	err = free_forks(states, states->number_philos);
	if (err)
		return (err);
	free(states->philos);
	return (err);
}
