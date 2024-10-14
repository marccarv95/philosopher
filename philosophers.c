/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccarv <marccarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:14:44 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/14 18:03:02 by marccarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_valuer		control;
	//pthread_t		munitor;
	t_point			*table;
	//pthread_t		*philo;
	//pthread_mutex_t	*forks;
	int				status;
	size_t				i = 0;
	size_t				j = 0;

	if (parse_argv(ac, av) == 1)
		return (0);
	init_valuer(&table, ft_atol(av[1]));
	init_control(&control, ac, av, table);
	//loop_forks(forks, ft_atol(av[1]));
	loop_philo(table, control);
	//pthread_create(&munitor, NULL, monitoring, table);
	//pthread_join(munitor, NULL);
	//loop_join(philo, ft_atol(av[1]));
	//loop_mutex_destroy(forks, ft_atol(av[1]));
	//pthread_mutex_destroy(control.mutex);
	//free(control.mutex);
	while (1)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
		{
			int exit_code = WEXITSTATUS(status);
			if (exit_code == 1)
			{
				while (i < control.av1)
				{
					printf("Enviando SIGKILL para o processo filho com PID: %d\n", table->kill_pid[i]);
					kill(table->kill_pid[i], SIGKILL);
				}
				sem_close(table->sem_ph);
    			sem_unlink("/philo_semaphore");
			}
			else if (exit_code == 0)
			{
				j++;
				if (j == control.av1)
				{
					printf("Pai: Todos os filhos terminaram de comer\n");
					sem_close(table->sem_ph);
    				sem_unlink("/philo_semaphore");
					break ;
				}
			}
        }
    }
	free(table->kill_pid);
	free(table);
	//free(forks);
	//free(philo);
	return (0);
}
