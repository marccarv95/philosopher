/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccarv <marccarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:49:31 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/07 13:03:08 by marccarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_point	*table_malloc(size_t nbr_philo)
{
	t_point	*table;

	if (nbr_philo == 0)
		return (NULL);
	table = (t_point *) malloc(sizeof(t_point) * nbr_philo);
	if (!table)
		return (NULL);
	return (table);
}

pthread_mutex_t	*forks_malloc(size_t nbr_philo)
{
	pthread_mutex_t	*forks;

	if (nbr_philo == 0)
		return (NULL);
	forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * nbr_philo);
	if (!forks)
		return (NULL);
	return (forks);
}

pthread_t	*philo_malloc(size_t nbr_philo)
{
	pthread_t	*philo;

	if (nbr_philo == 0)
		return (NULL);
	philo = (pthread_t *) malloc(sizeof(pthread_t) * nbr_philo);
	if (!philo)
		return (NULL);
	return (philo);
}

void	init_valuer(t_point **table, \
	pthread_mutex_t **forks, pthread_t **philo, size_t nbr_philo)
{
	*table = table_malloc(nbr_philo);
	*forks = forks_malloc(nbr_philo);
	*philo = philo_malloc(nbr_philo);
}

void	init_control(t_valuer *control, int ac, char **av)
{
	size_t	argv1;
	size_t	argv2;
	size_t	argv3;
	size_t	argv4;

	control->mutex = malloc(sizeof(pthread_mutex_t));
	if (!control->mutex)
		return ;
	pthread_mutex_init(control->mutex, NULL);
	argv1 = ft_atol(av[1]);
	argv2 = ft_atol(av[2]);
	argv3 = ft_atol(av[3]);
	argv4 = ft_atol(av[4]);
	sem_init(&control->sem, 1, argv1);
	control->ac = ac;
	control->av1 = argv1;
	control->av2 = argv2;
	control->av3 = argv3;
	control->av4 = argv4;
	if (ac == 6)
		control->av5 = ft_atol(av[5]);
	else
		control->av5 = -1;
}
