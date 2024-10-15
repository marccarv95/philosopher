/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:14:44 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/15 15:58:30 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	end_process(t_point *table, t_valuer control)
{
	size_t	i;

	i = 0;
	while (i < control.av1)
	{
		kill(table->kill_pid[i], SIGKILL);
		i++;
	}
	sem_close(table->sem_ph);
	sem_close(table->sem_print);
	free(table->kill_pid);
	exit (0);
	return ;
}

static void	end_dein(t_point *table)
{
	sem_close(table->sem_ph);
	sem_close(table->sem_print);
	free(table->kill_pid);
	exit(0);
	return ;
}

int	main(int ac, char **av)
{
	t_valuer		control;
	t_point			table;
	size_t			j;
	int				status;

	if (parse_argv(ac, av) == 1)
		return (0);
	init_control(&control, ac, av, &table);
	loop_philo(&table, control);
	j = 0;
	while (1)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 1)
			end_process(&table, control);
		else if (WEXITSTATUS(status) == 0)
		{
			j++;
			if (j == control.av1)
				end_dein(&table);
		}
	}
	return (0);
}
