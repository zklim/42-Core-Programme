/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:29:25 by zhlim             #+#    #+#             */
/*   Updated: 2023/09/12 01:08:23 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_forks(t_states *states)
{
	int	i;
	int	err;

	i = 0;
	while (i < states->number_philos)
	{
		err = pthread_mutex_init(&states->philos[i].fork.left, NULL);
		if (err)
		{
			free_forks(states, i);
			return (err);
		}
		i++;
	}
	i = 0;
	while (i < states->number_philos)
	{
		if (i == states->number_philos - 1)
			states->philos[i].fork.right = &states->philos[0].fork.left;
		else
			states->philos[i].fork.right = &states->philos[i + 1].fork.left;
		i++;
	}
	return (0);
}
