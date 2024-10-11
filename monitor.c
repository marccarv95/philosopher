/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccarv <marccarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:58:42 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/11 20:23:55 by marccarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	int	monitoring_one(t_point *table)
{
	size_t	i;

	i = 0;
	while (i < table[0].n_philo)
	{
		if (table[i].food == 0)
			i++;
		else
		{
			usleep(2000);
			if ((check_time(table[i].time_ut_r)) > table[i].t_to_die)
			{
				print_philo_stat("died", &table[i]);
				i = 0;
				while (i < table[0].n_philo)
					table[i++].val.x = 1;
				return (1);
			}
			i++;
		}
	}
	return (0);
}

void	*monitoring(void *arg)
{
	t_point	*table;
	size_t	j;

	table = (t_point *)arg;
	while (1)
	{
		if (monitoring_one(table))
			return (NULL);
		if (table->val.av5 > 0)
		{
			j = 0;
			while (table[j++].food == 0)
			{
				if (j == table->val.av1)
					return (NULL);
			}
		}
		usleep(1000);
	}
	return (NULL);
}
