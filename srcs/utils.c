/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:49:42 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/18 10:05:58 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	error_exit(const char *str)
{
	printf(BOLD RED "%s" RESERT, str);
	exit (1);
}

size_t	check_int_max(size_t nbr)
{
	if (nbr > INT_MAX)
		error_exit("error_very_large_value");
	return (nbr);
}

size_t	ft_atol(char *str)
{
	size_t	r;
	int		i;

	i = 0;
	r = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			error_exit("error_negative_value");
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		error_exit("error_incorrect_value");
	while (str[i] >= '0' && str[i] <= '9')
		r = r * 10 + (str[i++] - '0');
	return (r);
}

void	print_philo_stat(char *str, t_point *table)
{
	sem_wait(table->sem_print);
	printf(BOLD "%09ld %ld %s" RESERT, get_time_in_ms() - table->time_init, \
		table->pid_philo, str);
	if (table->val.z == 0)
		sem_post(table->sem_print);
}
