/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:52:46 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/15 15:59:19 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	loop_philo_one(t_point *table, t_valuer control, int i)
{
	table->food = control.av5;
	table->pid = fork();
	if (table->pid == 0)
	{
		free(table->kill_pid);
		table_rotina_par(table);
	}
	else
		table->kill_pid[i] = table->pid;
}

void	loop_philo(t_point *table, t_valuer control)
{
	size_t	i;
	size_t	tempo;

	i = 0;
	control.x = 0;
	tempo = get_time_in_ms();
	while (i < control.av1)
	{
		table->val = control;
		table->pid_philo = i + 1;
		table->n_philo = control.av1;
		table->t_to_die = control.av2;
		table->t_to_eat = control.av3;
		table->t_to_sleep = control.av4;
		table->time_init = tempo;
		table->time_ut_r = get_time_in_ms();
		loop_philo_one(table, control, i);
		i++;
	}
}
