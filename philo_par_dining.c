/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_par_dining.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccarv <marccarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:31:17 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/07 13:03:11 by marccarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	int	rotine_impar(t_point *table)
{
	if (pthread_mutex_lock(table->left_fork) == 0)
		pthread_mutex_unlock(table->left_fork);
	pthread_mutex_lock(table->right_fork);
	if (table->val.x == 1)
	{
		pthread_mutex_unlock(table->right_fork);
		return (1);
	}
	print_philo_stat("has taken a fork", table);
	if (table->n_philo == 1)
	{
		if (philo_one(table) == 1)
			return (1);
	}
	pthread_mutex_lock(table->left_fork);
	if (table->val.x == 1)
	{
		pthread_mutex_unlock(table->right_fork);
		pthread_mutex_unlock(table->left_fork);
		return (1);
	}
	print_philo_stat("has taken a fork", table);
	return (0);
}

static	int	rotine_par(t_point *table)
{
	if (pthread_mutex_lock(table->right_fork) == 0)
		pthread_mutex_unlock(table->right_fork);
	pthread_mutex_lock(table->left_fork);
	if (table->val.x == 1)
	{
		pthread_mutex_unlock(table->left_fork);
		return (1);
	}
	print_philo_stat("has taken a fork", table);
	pthread_mutex_lock(table->right_fork);
	if (table->val.x == 1)
	{
		pthread_mutex_unlock(table->left_fork);
		pthread_mutex_unlock(table->right_fork);
		return (1);
	}
	print_philo_stat("has taken a fork", table);
	return (0);
}

static	int	rotine_fork_two(t_point *table)
{
	if (table->val.x == 1)
	{
		pthread_mutex_unlock(table->right_fork);
		pthread_mutex_unlock(table->left_fork);
		return (1);
	}
	return (0);
}

static	int	rotine_cont(t_point *table)
{
	print_philo_stat("is eating", table);
	ft_sleep(table->t_to_eat);
	if (table->val.x == 1)
	{
		pthread_mutex_unlock(table->right_fork);
		pthread_mutex_unlock(table->left_fork);
		return (1);
	}
	pthread_mutex_unlock(table->right_fork);
	pthread_mutex_unlock(table->left_fork);
	table->time_ut_r = get_time_in_ms();
	if (table->food > 0)
		table->food--;
	if (table->val.x == 1 || table->food == 0)
		return (1);
	print_philo_stat("is sleeping", table);
	ft_sleep(table->t_to_sleep);
	if (table->val.x == 1)
		return (1);
	return (0);
}

void	*table_rotina_par(void *arg)
{
	t_point	*table;

	table = (t_point *)arg;
	while (1)
	{
		print_philo_stat("is thinking", table);
		if (table->pid_philo % 2 == 0)
		{
			if (rotine_par(table) == 1)
				return (NULL);
		}
		else
		{
			if (rotine_impar(table) == 1)
				return (NULL);
		}
		if (rotine_fork_two(table) == 1)
			return (NULL);
		if (rotine_cont(table) == 1)
			return (NULL);
		if (table->val.x == 1)
			return (NULL);
	}
	return (NULL);
}
