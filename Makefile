# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marccarv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 14:33:53 by marccarv          #+#    #+#              #
#    Updated: 2024/09/18 14:43:44 by marccarv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE = philosophers.c parsing_argv.c philo_impar_dining.c utils.c \
		philo_init.c monitor.c time.c set_table.c set_table_2.c philo_par_dining.c
OBJC = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJC)
	$(CC) $(CFLAGS) $(OBJC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJC)

fclean: clean
	rm -f $(NAME)

re: clean fclean all