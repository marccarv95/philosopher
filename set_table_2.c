/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccarv <marccarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:02:43 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/07 13:03:36 by marccarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_one(t_point *table)
{
	ft_sleep(table->t_to_die + 10);
	if (table->val.x == 1)
	{
		pthread_mutex_unlock(table->right_fork);
		return (1);
	}
	return (0);
}
