# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 15:51:06 by mde-avel          #+#    #+#              #
#    Updated: 2024/03/04 19:14:45 by mde-avel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -pthread -g 
#-fsanitize=address 
#-fsanitize=thread

RM = rm -f

SRCS = eat.c main.c routine.c utils.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

val:
	@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./philo 4 310 200 100

# ./philo 1 800 200 200
# ./philo 5 800 200 200 3
# ./philo 4 410 200 200 3
# ./philo 4 310 200 100