/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:14:44 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/15 13:49:19 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_valuer		control;
	t_point			table;
	int				status;
	size_t				i = 0;
	size_t				j = 0;

	if (parse_argv(ac, av) == 1)
		return (0);
	init_control(&control, ac, av, &table);
	loop_philo(&table, control);
	int exit_code;
	usleep(4000);
	while (1)
	{
		waitpid(-1, &status, 0);
		exit_code = WEXITSTATUS(status);
		printf("Pai: O processo filho terminou com código de saída: %d\n", exit_code);
		if (exit_code == 1)
		{
			while (i < control.av1)
			{
				printf("Enviando SIGKILL para o processo filho com PID: %d\n", table.kill_pid[i]);
				kill(table.kill_pid[i], SIGKILL);
				i++;
			}
			sem_close(table.sem_ph);
			sem_close(table.sem_print);
			free(table.kill_pid);
			exit (0);
		}
		else if (exit_code == 0)
		{
			j++;
			if (j == control.av1)
			{
				printf("Pai: Todos os filhos terminaram de comer\n");
				sem_close(table.sem_ph);
				sem_close(table.sem_print);
				free(table.kill_pid);
				exit(0);
			}
		}
    }
	
	return (0);
}
