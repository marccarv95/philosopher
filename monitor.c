/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccarv <marccarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:58:42 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/14 17:38:35 by marccarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	int	monitoring_one(t_point *table)
{
	usleep(2000);
	if (table->food == 0)
			return (1);
	if ((check_time(table->time_ut_r)) > table->t_to_die)
	{
		print_philo_stat("died", table);
		table->val.x = 1;
		return (1);
	}
	if (table->food == 0)
		return (1);
	return (0);
}

void	*monitoring(void *arg)
{
	t_point	*table;

	table = (t_point *)arg;
	while (1)
	{
		if (table->food == 0)
			return (NULL);
		if (monitoring_one(table) == 1)
			return (NULL);
		if (table->food == 0)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
