/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 00:25:23 by ajamoun           #+#    #+#             */
/*   Updated: 2025/07/17 16:47:05 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_is_dead(t_philo *philo)
{
	bool	is_dead;

	pthread_mutex_lock(&philo->data->mutex.death);
	is_dead = philo->data->death_happened;
	pthread_mutex_unlock(&philo->data->mutex.death);
	return (is_dead);
}

static int	check_death(t_philo *philo)
{
	t_timestamp		inactive_time;
	int				eats;
	int				nbr_of_philos;

	pthread_mutex_lock(&philo->data->mutex.meal);
	eats = philo->data->all_eats;
	inactive_time = get_current_time() - philo->last_meal_time;
	pthread_mutex_unlock(&philo->data->mutex.meal);
	nbr_of_philos = philo->data->nbr_of_philos;
	if (inactive_time >= philo->data->time_to_die || eats == nbr_of_philos)
	{
		if (!philo_is_dead(philo))
		{
			if (eats != nbr_of_philos)
				print_state(philo, "died");
			pthread_mutex_lock(&philo->data->mutex.death);
			philo->data->death_happened = true;
			pthread_mutex_unlock(&philo->data->mutex.death);
		}
	}
	return (philo_is_dead(philo));
}

void	monitor_death(t_philo *philos)
{
	int	i;

	while (true)
	{
		i = 0;
		while (i < philos->data->nbr_of_philos)
		{
			if (check_death(&philos[i]))
				return ;
			i++;
		}
		usleep(500);
	}
}
