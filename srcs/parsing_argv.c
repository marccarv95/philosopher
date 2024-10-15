/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:35:14 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/15 16:16:21 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static	int	valid_caracter(char c)
{
	return ((c >= '0' && c <= '9') || c == '+');
}

static	int	valid_number(char *str, int i)
{
	if (str[i] == '+' && (str[i - 1] >= '0' && str[i - 1] <= '9'))
		return (0);
	if (str[i] == '+' && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (0);
	return (1);
}

static int	error_argv(char **av)
{
	int	i;
	int	j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (!valid_caracter(av[j][i]) || !valid_number(av[j], i))
			{
				printf("Error invalid numbers or Caracter\n");
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	food(int ac, char **av)
{
	if (ac == 6 && ft_atol(av[5]) == 0)
		return (1);
	return (0);
}

int	parse_argv(int ac, char **av)
{
	if (ac < 5)
	{
		printf("Error lacking number of arguments\n");
		return (1);
	}
	else if (ac > 6)
	{
		printf("Error to many arguments\n");
		return (1);
	}
	if (error_argv(av) == 1)
		return (1);
	if (food(ac, av) == 1)
		return (1);
	if (ft_atol(av[1]) == 0)
		return (1);
	return (0);
}
