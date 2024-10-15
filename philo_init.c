/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:49:31 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/15 14:58:24 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_control(t_valuer *control, int ac, char **av, t_point *table)
{
	size_t	argv1;
	size_t	argv2;
	size_t	argv3;
	size_t	argv4;

	argv1 = ft_atol(av[1]);
	argv2 = ft_atol(av[2]);
	argv3 = ft_atol(av[3]);
	argv4 = ft_atol(av[4]);
	control->ac = ac;
	control->av1 = argv1;
	control->av2 = argv2;
	control->av3 = argv3;
	control->av4 = argv4;
	table->kill_pid = malloc(sizeof(pid_t) * argv1);
	if (!table->kill_pid)
		return;
	table->sem_ph = sem_open("/philo_semaphore", O_CREAT | O_EXCL, 0644, control->av1);
	table->sem_print = sem_open("/philo_print", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("/philo_semaphore");
	sem_unlink("/philo_print");
	if (ac == 6)
		control->av5 = ft_atol(av[5]);
	else
		control->av5 = -1;
}
