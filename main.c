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

static int  philos_checker(t_data *data, t_philo **philos, int ac, char **av)
{
    if(validate_args(ac - 1, av + 1))
    {
        error_message("Error: At least one argument is not valid.\n");
		return (EXIT_FAILURE);
    }
}
int main(int ac, char **av)
{
    if(av != 5 || av != 6)
    {
        error_message("Error: Invalid number of arguments, Expected 5 or 6.\n");
        return (EXIT_FAILURE);
    }
    if(ac == 6 && atoi(av[5]) < 0)
        return (EXIT_SUCCESS);
}
