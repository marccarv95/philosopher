/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dining.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:31:17 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/15 16:05:15 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	void	rotine(t_point *table)
{
	sem_wait(table->sem_ph);
	checker_one(table);
	print_philo_stat("has taken a fork", table);
	if (table->n_philo == 1)
	{
		if (philo_one(table) == 1)
			exit (1);
	}
	sem_wait(table->sem_ph);
	checker_two(table);
	print_philo_stat("has taken a fork", table);
	return ;
}

static	void	rotine_cont(t_point *table)
{
	print_philo_stat("is eating", table);
	table->time_ut_r = get_time_in_ms();
	ft_sleep(table->t_to_eat);
	checker_two(table);
	sem_post(table->sem_ph);
	sem_post(table->sem_ph);
	if (table->food > 0)
		table->food--;
	if (table->food == 0)
		checker_three(table, 0);
	if (table->val.x == 1)
	{
		sem_close(table->sem_ph);
		sem_close(table->sem_print);
		exit (1);
	}
	print_philo_stat("is sleeping", table);
	ft_sleep(table->t_to_sleep);
	if (table->val.x == 1)
		checker_three(table, 1);
	return ;
}

void	table_rotina_par(t_point *table)
{
	pthread_create(&table->munitor, NULL, monitoring, table);
	pthread_detach(table->munitor);
	while (1)
	{
		print_philo_stat("is thinking", table);
		rotine(table);
		rotine_cont(table);
		if (table->val.x == 1)
		{
			sem_close(table->sem_ph);
			sem_close(table->sem_print);
			exit (1);
		}
	}
	return ;
}
