# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 14:33:53 by marccarv          #+#    #+#              #
#    Updated: 2024/10/16 13:58:33 by almanuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
SOURCE = 	srcs/philosophers.c \
			srcs/parsing_argv.c \
			srcs/philo_dining.c \
			srcs/utils.c		\
			srcs/philo_init.c	\
			srcs/monitor.c		\
			srcs/time.c			\
			srcs/set_table.c	\
			srcs/set_table_2.c

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
