/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:14:41 by ajamoun           #+#    #+#             */
/*   Updated: 2025/06/10 20:14:41 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

typedef unsigned long	t_timestamp;

typedef struct s_mutex
{
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death;
	pthread_mutex_t	meal;
}				t_mutex;

typedef struct s_data
{
	int				nbr_of_philos;
	int				all_eats;
	int				must_eats;
	bool			death_happened;
	t_timestamp		time_to_die;
	t_timestamp		time_to_eat;
	t_timestamp		time_to_sleep;
	t_timestamp		start_time;
	t_mutex			mutex;
}				t_data;

typedef struct s_philo
{
	int				id;
	int				right_fork;
	int				left_fork;
	int				meals_count;
	t_data			*data;
	pthread_t		thread;
	t_timestamp		last_meal_time;
	bool			finished;
}				t_philo;

//philo functions
void		cleanup(t_philo **philo);
t_timestamp	get_current_time(void);
void		ft_usleep(t_timestamp	time, t_philo *philo);
void		print_state(t_philo	*philo, char *state);
void		must_eats(t_philo *philo);
void		pick_up_forks(t_philo *philo);
void		eat(t_philo *philo);
void		put_down_forks(t_philo *philo);
void		sleep_philo(t_philo *philo);
void		think(t_philo *philo);
int			begin_simulation(t_philo *philos);
bool	philo_is_dead(t_philo *philo);
void	monitor_death(t_philo *philos);
// helper functions
int			error_message(char *error_message);
int			validate_args(int ac, char **av);
//libc functions
int			ft_atoi(const char *str);
int	ft_strlen(const char *s);
#endif