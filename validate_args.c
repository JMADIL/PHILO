/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:52:48 by ajamoun           #+#    #+#             */
/*   Updated: 2025/06/04 16:52:48 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int validate_args(int ac, char **av)

    int i;
    int num_of_philos;

    num_of_philos = ft_atoi(av[0]);
    if(num_of_philos > 200 || num_of_philos <= 0)
    {
        error_message("Error: Number of philosophers must be between 1 and 200.\n");
        return (EXIT_FAILURE);
    }


