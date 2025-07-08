/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:14:34 by ajamoun           #+#    #+#             */
/*   Updated: 2025/06/10 20:14:34 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_mutexes(t_data *data)
{
    int i;

    i = -1;
    pthread_mutex_init(&data->mutex.print, NULL);
    pthread_mutex_init(&data->mutex.death, NULL);
    pthread_mutex_init(&data->mutex.meal, NULL);
    while(++i < data->nbr_of_philos)
        pthread_mutex_init(&data->mutex.fork[i], NULL);
}

int init_data(char *av[], t_data *data, int must_eats)
{
    data->mutex.fork = malloc(data->nbr_of_philos * sizeof(pthread_mutex_t));
    if(!data->mutex.fork)
        return (EXIT_FAILURE);
    data->nbr_of_philos = ft_atoi(av[0]);
    data->time_to_die = ft_atoi(av[1]);
    data->time_to_eat = ft_atoi(av[2]);
    data->time_to_sleep = ft_atoi(av[3]);
    data->death_happened = false;
    data->all_eats = 0;
    // if the user provided 6 args the program will pass must_eats as true
    if(must_eats)
        data->must_eats = av[4];
    else
        data->must_eats = -1;
    //init mutexes we give it data to initialize the fucking mutexes
    ------->>>>> init_mutexes(data); <<<<---------

    return (EXIT_SUCCESS);
}
static int  philos_checker(t_data *data, t_philo **philos, int ac, char **av)
{
    if(validate_args(ac - 1, av + 1))
    {
        error_message("Error: At least one argument is not valid.\n");
		return (EXIT_FAILURE);
    }
    if(init_data(av + 1, data, (ac == 6)) || ------>>> init_philos() <<<<<-----)
    {
        error_message("Error: Malloc failed.\n"y);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
int main(int ac, char **av)
{
    if(av != 5 || av != 6)
    {
        error_message("Error: Invalid number of arguments, Expected 5 or 6.\n");
        return (EXIT_FAILURE);
    }
    if(ac == 6 && ft_atoi(av[5]) < 0)
        return (EXIT_SUCCESS);
}
