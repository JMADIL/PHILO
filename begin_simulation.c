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

void *routine(void *arg)
{
    t_philo *philos = (t_philo *)arg;
    if(philos->data->nbr_of_philos == 1)
       return --->>> one_fork(philos); <<<---
    

}
int begin_simulation(t_philo *philos)
{
    int i;

    i = -1;
    philos->data->start_time = --->>> get_current_time() <<<---;
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
