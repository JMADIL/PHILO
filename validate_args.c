/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/06/10 20:14:59 by ajamoun           #+#    #+#             */
/*   Updated: 2025/06/10 20:14:59 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (EXIT_FAILURE);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] != '\0')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	validate_args(int ac, char **av)
{
	int	i;
	int	num_of_philos;

	num_of_philos = ft_atoi(av[0]);
	if (num_of_philos > 200 || num_of_philos <= 0)
	{
		error_message("Error: Number of philosophers must be between 1 and 200.\n");
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < ac)
	{
		if (av[i][0] == '\0' || ft_isdigit(av[i]) || ft_atoi(av[i]) < 0)
			return (EXIT_FAILURE);
		if (i > 0 && ft_atoi(av[i]) == 0)
		{
			error_message("Error: Time values must be positive.\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
