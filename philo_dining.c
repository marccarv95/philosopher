/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dining.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:31:17 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/15 13:09:24 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	int	rotine(t_point *table, int i)
{
	sem_wait(table->sem_ph);
	if (table->val.x == 1)
	{
		sem_post(table->sem_ph);
		exit (1);
	}
	print_philo_stat("has taken a fork", table);
	if (table->n_philo == 1)
	{
		if (philo_one(table) == 1)
			exit (1);
	}
	if(sem_wait(table->sem_ph) != 0)
	{
		sem_post(table->sem_ph);
		i ++;
		return (1);
	}
	if (table->val.x == 1)
	{
		sem_post(table->sem_ph);
		sem_post(table->sem_ph);
		exit (1);
	}
	print_philo_stat("has taken a fork", table);
	return (0);
}

static	void	rotine_cont(t_point *table)
{
	print_philo_stat("is eating", table);
	table->time_ut_r = get_time_in_ms();	
	ft_sleep(table->t_to_eat);
	if (table->val.x == 1)
	{
		sem_post(table->sem_ph);
		sem_post(table->sem_ph);
		exit (1);
	}
	sem_post(table->sem_ph);
	sem_post(table->sem_ph);
	if (table->food > 0)
		table->food--;
	if (table->food == 0)
	{
		usleep(4000);
		exit (0);
	}
	if (table->val.x == 1)
	{
		usleep(1000);
		exit (1);
	}
	print_philo_stat("is sleeping", table);
	ft_sleep(table->t_to_sleep);
	if (table->val.x == 1)
		exit (1);
}

void	table_rotina_par(t_point *table)
{
	pthread_t		munitor;
	int				i = 0;

	pthread_create(&munitor, NULL, monitoring, table);
	pthread_detach(munitor);
	while (1)
	{
		print_philo_stat("is thinking", table);
		rotine(table, i);
		if (i == 0)
			rotine_cont(table);
		i = 0;
		if (table->val.x == 1)
			exit (1);
	}
}
