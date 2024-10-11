/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccarv <marccarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:36:37 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/07 13:03:40 by marccarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	check_time(size_t time_init)
{
	return (get_time_in_ms() - time_init);
}

size_t	get_time_in_ms(void)
{
	struct timeval	tempo;

	if (gettimeofday(&tempo, NULL))
		return (0);
	return ((tempo.tv_sec * 1000) + (tempo.tv_usec / 1000));
}

void	ft_sleep(size_t time)
{
	_Atomic size_t	count;

	count = get_time_in_ms() + time;
	while (get_time_in_ms() < count)
		usleep(100);
}
