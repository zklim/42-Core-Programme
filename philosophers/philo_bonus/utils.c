/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:56:40 by zhlim             #+#    #+#             */
/*   Updated: 2023/09/12 17:29:24 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	nbr_ft(const char *str, int sign)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str++ - '0');
		i++;
		if (i >= 20 && sign > 0)
			return (-1);
		else if (i >= 20 && sign < 0)
			return (0);
	}
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return (nbr_ft(str, sign));
}

long	get_timestamp(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

void	ft_usleep(int i)
{
	long	start;

	start = get_timestamp();
	while (get_timestamp() - start < i)
		usleep(500);
}

void	ft_print(t_philo *philo, t_actions type)
{
	pthread_mutex_lock(&philo->lock);
	if (type == FORK_LEFT)
		printf(RED "%d %d has taken a fork\n" RESET, philo->now, philo->id);
	else if (type == FORK_RIGHT)
		printf(MAGENTA "%d %d has taken a fork\n" RESET, philo->now, philo->id);
	else if (type == EAT)
		printf(GREEN "%d %d is eating\n" RESET, philo->last_eat, philo->id);
	else if (type == SLEEP)
		printf(BLUE "%d %d is sleeping\n" RESET, philo->now, philo->id);
	else if (type == THINK)
		printf(CYAN "%d %d is thinking\n" RESET, philo->now, philo->id);
	pthread_mutex_unlock(&philo->lock);
}
