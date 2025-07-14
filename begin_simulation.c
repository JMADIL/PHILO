/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:13:02 by ajamoun           #+#    #+#             */
/*   Updated: 2025/07/13 16:13:02 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
void *one_philo(t_philo *philo)
{
    think(philo);
    pthread_mutex_lock(&philo->data->mutex.forks[philo->right_fork]);
    print_state(philo, "has taken a fork");
    t_usleep(philo->data->time_to_die, philo);
    print_state(philo, "died");
    pthread_mutex_unlock(&philo->data->mutex.forks[philo->right_fork]); 
    return (NULL);
}
void *routine(void *arg)
{
    t_philo *philos = (t_philo *)arg;
    if(philos->data->nbr_of_philos == 1)
       return (one_philo(philos));
    if(philos.id % 2 == 0)
        usleep(1000);
    while(!--->>> is_dead(philos) <<<---)
    {
        think(philos);
        pick_up_forks(philos);
        eat(philos);
        put_down_forks(philos);
        sleep(philos);
    }
    return (NULL);
}
int begin_simulation(t_philo *philos)
{
    int i;

    i = -1;
    philos->data->start_time = get_current_time();
    while(++i < philos->data->nbr_of_philos)
    {
        philos[i].last_meal_time = philos->data->start_time;
        if(pthread_create(&philos[i].thread, NULL, routine, &philos[i]) != '\0')
        {
            error_message("Error: Failed to create threads.\n");
            return (EXIT_FAILURE);
        }
    }
    if(philo->data->nbr_of_philos > 1)
        --->>> monitor_death(); <<<---
    i = -1;
    while(++i < philo->data->nbr_of_philos)
        pthread_join(&philos[i].thread, NULL);
    return (EXIT_SUCCESS);
}

