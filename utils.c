/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:09:25 by ajamoun           #+#    #+#             */
/*   Updated: 2025/06/04 17:09:25 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	prev_res;	

	res = 0;
	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		prev_res = res;
		res = res * 10 + (str[i] - '0');
		if (prev_res > res)
			return (-1);
		i++;
	}
	return (res);
}