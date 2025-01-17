/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:02:43 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/18 10:05:07 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	checker_one(t_point *table)
{
	if (table->val.x == 1)
	{
		sem_post(table->sem_ph);
		return (1);
	}
	return (0);
}

int	checker_two(t_point *table)
{
	if (table->val.x == 1)
	{
		sem_post(table->sem_ph);
		sem_post(table->sem_ph);
		return (1);
	}
	return (0);
}

void	checker_three(t_point *table, int n)
{
	sem_close(table->sem_ph);
	sem_close(table->sem_print);
	usleep (5000);
	exit (n);
	return ;
}

int	philo_one(t_point *table)
{
	ft_sleep(table->t_to_die + 10);
	if (table->val.x == 1)
	{
		sem_post(table->sem_ph);
		sem_close(table->sem_ph);
		sem_close(table->sem_print);
		exit (1);
	}
	return (0);
}
