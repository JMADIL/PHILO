/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/06/11 21:18:06 by ajamoun           #+#    #+#             */
/*   Updated: 2025/06/11 21:18:06 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_message(char *error_message)
{
	int	len;

	len = ft_strlen(error_message) + 1;
	write(2, error_message, len);
	return (len);
}

t_timestamp	get_current_time(void)
{
	struct timeval tv;
	t_timestamp	miliseconds;

	gettimeofday(&tv, NULL);
	miliseconds = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (miliseconds);
}

void	ft_usleep(t_timestamp	time, t_philo *philo)
{
	t_timestamp	wake_up;
	wake_up = get_current_time() + time;
	while(get_current_time() < wake_up)
	{
		if(--->>> is_dead(philo); <<<---)
			break;
		usleep(500);
	}
}

void	print_state(t_philo	*philo, char *state)
{
	if(!--->>> is_dead(philo); <<<---)
	{
		pthread_mutex_lock(&philo->data->mutex.print);
		//double protection
		if(!--->>> is_dead(philo); <<<---)
			printf("%-5lu %-4d %s\n", get_current_time()
				- philo->data->start_time, philo->id, state);
		pthread_mutex_unlock(&philo->data->mutex.print);
	}
}

void	must_eats(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex.meal);
	if (philo->data->must_eats > -1)
	{
		philo->meals_count++;
		if (philo->meals_count >= philo->data->must_eats && !philo->finished)
		{
			philo->data->all_eats++;
			philo->finished = true;
		}
	}
	pthread_mutex_unlock(&philo->data->mutex.meal);
}
