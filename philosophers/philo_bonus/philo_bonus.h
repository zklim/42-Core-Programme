/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:50:15 by zhlim             #+#    #+#             */
/*   Updated: 2023/09/12 18:41:14 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>
# include <signal.h>

# define RESET "\x1B[0m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN "\x1B[36m"

typedef enum e_actions
{
	FORK_LEFT,
	FORK_RIGHT,
	EAT,
	SLEEP,
	THINK,
	DIED
}	t_actions;

typedef struct s_philo
{
	pid_t			pid;
	int				id;
	int				now;
	int				last_eat;
	int				eat_count;
	pthread_t		monitor;
	pthread_mutex_t	lock;
	struct s_states	*states;
}					t_philo;

typedef struct s_sem
{
	sem_t			*forks;
	sem_t			*dead;
	sem_t			*eats;
	sem_t			*print;
}				t_sem;

typedef struct s_states
{
	int				number_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	int				finish_eat;
	long			start;
	t_philo			*philos;
	t_sem			sem;
	pid_t			sem_eat;
}					t_states;

int					create_philo(t_states *states);
void				free_philo(t_philo *philos);
int					ft_free(t_states *states);
void				ft_print(t_philo *philo, t_actions type);
void				ft_usleep(int i);
long				get_timestamp(void);
int					nbr_ft(const char *str, int sign);
int					ft_atoi(const char *str);
void				*monitor(void *args);
int					is_dead(t_philo *philo);
void				ft_fork(t_states *states);
void				ft_sem_close(t_states *states);
void				ft_sem_unlink(void);
void				routine(t_philo *philo);

#endif