/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:52:04 by ajamoun           #+#    #+#             */
/*   Updated: 2025/07/15 19:03:45 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_philo *philo)
{
	int	i;

	i = 0;
	if ((*philo))
	{
		while (i < (*philo)->data->nbr_of_philos)
		{
			pthread_mutex_destroy(&(*philo)->data->mutex.forks[i]);
			i++;
		}
		pthread_mutex_destroy(&(*philo)->data->mutex.meal);
		pthread_mutex_destroy(&(*philo)->data->mutex.print);
		pthread_mutex_destroy(&(*philo)->data->mutex.death);
		free((*philo)->data->mutex.forks);
		free(*philo);
		(*philo) = NULL;
	}
}
