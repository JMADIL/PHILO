/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:16:12 by ajamoun           #+#    #+#             */
/*   Updated: 2025/07/17 16:54:08 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_up_forks(t_philo *philo)
{
	int	first;
	int	second;

	if (philo->left_fork < philo->right_fork)
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	else
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	pthread_mutex_lock(&philo->data->mutex.forks[first]);
	print_state(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->mutex.forks[second]);
	print_state(philo, "has taken a fork");
}

void	eat(t_philo *philo)
{
	print_state(philo, "is eating");
	pthread_mutex_lock(&philo->data->mutex.meal);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&philo->data->mutex.meal);
	ft_usleep(philo->data->time_to_eat, philo);
	must_eats(philo);
}

void	put_down_forks(t_philo *philo)
{
	int	first;
	int	second;

	if (philo->left_fork < philo->right_fork)
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	else
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	pthread_mutex_unlock(&philo->data->mutex.forks[second]);
	pthread_mutex_unlock(&philo->data->mutex.forks[first]);
}

void	sleep_philo(t_philo *philo)
{
	print_state(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep, philo);
}

void	think(t_philo *philo)
{
	print_state(philo, "is thinking");
}
