/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccarv <marccarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:15:05 by marccarv          #+#    #+#             */
/*   Updated: 2024/10/14 18:02:19 by marccarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>
# include <limits.h>
# include <semaphore.h>
# include <sys/types.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
//# include <stdatomic.h>

# define BOLD "\033[1m"
# define RED "\033[31m"
# define GREED "\033[32m"
# define RESERT "\033[0m\n"

typedef struct s_valuer
{
	//pthread_mutex_t	*mutex;
	_Atomic int		x;
	size_t			av1;
	size_t			av2;
	size_t			av3;
	size_t			av4;
	size_t			av5;
	int				ac;
}	t_valuer;

typedef struct s_point
{
	sem_t			*sem_ph;
	sem_t			*sem_print;
	t_valuer		val;
	pid_t			pid;
	pid_t			*kill_pid;
	_Atomic size_t	time_ut_r;
	_Atomic int		food;
	size_t			time_init;
	size_t			n_philo;
	size_t			t_to_die;
	size_t			t_to_eat;
	size_t			pid_philo;
	int				t_to_sleep;
}	t_point;

pthread_mutex_t	*forks_malloc(size_t nbr_philo);

t_point			*table_malloc(size_t nbr_philo);
pthread_t		*philo_malloc(size_t nbr_philo);

void			print_philo_stat(char *str, t_point *table);
void			error_exit(const char *str);
void			init_valuer(t_point **table, size_t nbr_philo);
void			loop_philo(t_point *table, t_valuer control);
//void			loop_join(pthread_t *philo, size_t nbr_philo);
//void			loop_mutex_destroy(pthread_mutex_t *forks, size_t nbr_philo);
void			init_control(t_valuer *control, int ac, char **av, t_point *table);
void			ft_sleep(size_t time);
void			table_rotina_par(t_point *table);
void			*monitoring(void *arg);

size_t			check_time(size_t time_init);
size_t			check_int_max(size_t nbr);
size_t			control(t_point	*table, size_t time);
size_t			ft_atol(char *str);
size_t			time_philo(size_t time);
size_t			get_time_in_ms(void);

int				parse_argv(int ac, char **av);
int				philo_one(t_point *table);

#endif
