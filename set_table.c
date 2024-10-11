/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccarv <marccarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:52:46 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/11 20:23:47 by marccarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
/*
void	loop_forks(pthread_mutex_t *forks, size_t nbr_philo)
{
	size_t	i;

	i = 0;
	while (i < nbr_philo)
		pthread_mutex_init(&forks[i++], NULL);
}
*/
void	loop_philo_one(pthread_t *philo, \
	t_point *table, t_valuer control, int i)
{
	table[i].food = control.av5;
	if (table[i].n_philo % 2 == 0)
	{
		table_rotina_par(table);
		//pthread_create(philo + i, NULL, table_rotina_par, &table[i]);
	}
	/*else
	{
		table_rotina_impar(table);
		//pthread_create(philo + i, NULL, table_rotina_impar, &table[i]);
	}*/
}

void	loop_philo(pthread_t *philo, t_point *table, \
	pthread_mutex_t *forks, t_valuer control)
{
	size_t	i;
	size_t	tempo;
	size_t	nbr_philo;

	i = 0;
	control.x = 0;
	nbr_philo = control.av1;
	tempo = get_time_in_ms();
	while (i < nbr_philo)
	{
		table[i].val = control;
		table[i].pid_philo = i + 1;
		table[i].n_philo = nbr_philo;
		table[i].t_to_die = control.av2;
		table[i].t_to_eat = control.av3;
		table[i].t_to_sleep = control.av4;
		//table[i].left_fork = &forks[i];
		//table[i].right_fork = &forks[(i + 1) % nbr_philo];
		table[i].time_init = tempo;
		table[i].time_ut_r = get_time_in_ms();
		loop_philo_one(philo, table, control, i);
		i++;
	}
}
/*
void	loop_join(pthread_t *philo, size_t nbr_philo)
{
	size_t	i;

	i = 0;
	while (i < nbr_philo)
	{
		if (pthread_join(philo[i], NULL) != 0)
			perror("Erro ao fazer join na thread do filósofo");
		i++;
	}
}

void	loop_mutex_destroy(pthread_mutex_t *forks, size_t nbr_philo)
{
	size_t	i;

	i = 0;
	while (i < nbr_philo)
		pthread_mutex_destroy(&forks[i++]);
}*/
