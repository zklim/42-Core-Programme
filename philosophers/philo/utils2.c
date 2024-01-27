/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:53:14 by zhlim             #+#    #+#             */
/*   Updated: 2023/09/10 17:12:39 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->states->lock);
	if (philo->states->someone_died)
	{
		pthread_mutex_unlock(&philo->states->lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->states->lock);
	return (0);
}
