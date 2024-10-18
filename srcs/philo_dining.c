/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dining.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:31:17 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/18 10:02:36 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static	int	rotine(t_point *table)
{
	if ((table->n_philo % 2) != 0)
	{
		if ((table->pid_philo % 2) == 0)
			ft_sleep(50);
	}
	sem_wait(table->sem_ph);
	if (checker_one(table))
		return (1);
	print_philo_stat("has taken a fork", table);
	if (table->n_philo == 1)
	{
		if (philo_one(table) == 1)
			exit (1);
	}
	sem_wait(table->sem_ph);
	if (checker_two(table))
		return (1);
	print_philo_stat("has taken a fork", table);
	return (0);
}

static	int	rotine_cont(t_point *table)
{
	print_philo_stat("is eating", table);
	table->time_ut_r = get_time_in_ms();
	ft_sleep(table->t_to_eat);
	if (checker_two(table))
		return (1);
	sem_post(table->sem_ph);
	sem_post(table->sem_ph);
	if (table->food > 0)
		table->food--;
	if (table->food == 0)
		checker_three(table, 0);
	if (table->val.x == 1)
		return (1);
	print_philo_stat("is sleeping", table);
	ft_sleep(table->t_to_sleep);
	if (table->val.x == 1)
		return (1);
	return (0);
}

void	table_rotina_par(t_point *table)
{
	pthread_create(&table->munitor, NULL, monitoring, table);
	pthread_detach(table->munitor);
	while (1)
	{
		print_philo_stat("is thinking", table);
		if (rotine(table))
			break ;
		if (rotine_cont(table))
			break ;
		if (table->val.x == 1)
			break ;
	}
	return ;
}
