/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccarv <marccarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:14:44 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/07 13:03:15 by marccarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_valuer		control;
	pthread_t		munitor;
	t_point			*table;
	pthread_t		*philo;
	pthread_mutex_t	*forks;

	if (parse_argv(ac, av) == 1)
		return (0);
	init_control(&control, ac, av);
	init_valuer(&table, &forks, &philo, ft_atol(av[1]));
	loop_forks(forks, ft_atol(av[1]));
	loop_philo(philo, table, forks, control);
	pthread_create(&munitor, NULL, monitoring, table);
	pthread_join(munitor, NULL);
	loop_join(philo, ft_atol(av[1]));
	loop_mutex_destroy(forks, ft_atol(av[1]));
	pthread_mutex_destroy(control.mutex);
	free(control.mutex);
	free(table);
	free(forks);
	free(philo);
	return (0);
}
