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

static void init_mutexes(t_data *data)
{
    int i;

    i = -1;
    pthread_mutex_init(&data->mutex.print, NULL);
    pthread_mutex_init(&data->mutex.death, NULL);
    pthread_mutex_init(&data->mutex.meal, NULL);
    while(++i < data->nbr_of_philos)
        pthread_mutex_init(&data->mutex.forks[i], NULL);
}
static int init_data(char *av[], t_data *data, int must_eats)
{
    data->nbr_of_philos = ft_atoi(av[0]);
    data->time_to_die = ft_atoi(av[1]);
    data->time_to_eat = ft_atoi(av[2]);
    data->time_to_sleep = ft_atoi(av[3]);
    data->death_happened = false;
    data->all_eats = 0;
    data->mutex.forks = malloc(data->nbr_of_philos * sizeof(pthread_mutex_t));
    if(!data->mutex.forks)
    return (EXIT_FAILURE);
    // if the user provided 6 args the program will pass must_eats as true
    if(must_eats)
        data->must_eats = ft_atoi(av[4]);
    else
        data->must_eats = -1;
    //init mutexes we give it data to initialize the fucking mutexes
    init_mutexes(data);

    return (EXIT_SUCCESS);
}

static int init_philos(t_philo **philos, t_data *data)
{
    *philos = (t_philo *) malloc(sizeof(t_philo) * data->nbr_of_philos);
    if(!(*philos))
        return (EXIT_FAILURE);
    int i;

    i = 0;
    while(i < data->nbr_of_philos)
    {
        (*philos)[i].id = i + 1;
        (*philos)[i].data = data;
        (*philos)[i].meals_count = 0;
        (*philos)[i].finished = false;
        (*philos)[i].left_fork = i;
        (*philos)[i].right_fork = (i + 1) % data->nbr_of_philos;
        i++;
    }
    return(EXIT_SUCCESS);
}

static int  philos_checker(t_data *data, t_philo **philos, int ac, char **av)
{
    if(validate_args(ac - 1, av + 1))
    {
        error_message("Error: At least one argument is not valid.\n");
		return (EXIT_FAILURE);
    }
    if(init_data(av + 1, data, (ac == 6)) || init_philos(philos, data))
    {
        error_message("Error: Malloc failed.\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
int main(int ac, char **av)
{
    t_data data;
	t_philo	*philos;
    
    if(ac != 5 && ac != 6)
    {
        error_message("Error: Invalid number of arguments, Expected 5 or 6.\n");
        return (EXIT_FAILURE);
    }
    if(ac == 6 && ft_atoi(av[ac - 1]) == 0)
        return (EXIT_SUCCESS);
    //Now you should add the philos_checker
    if(philos_checker(&data, &philos , ac, av))
         return (EXIT_FAILURE);
    if(begin_simulation(philos))
    {
        //if philos_checker return 1 then i should clean this shit
        cleanup(&philos);
        return (EXIT_FAILURE);
    }
    // in this if statement we add the simulation 
    // so we should add the simulation function and the cleanup function
    cleanup(&philos);
    return (EXIT_SUCCESS);
}
