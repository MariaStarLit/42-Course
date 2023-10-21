# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 14:42:17 by mde-avel          #+#    #+#              #
#    Updated: 2023/10/20 18:16:47 by mde-avel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_PREFIX = ./src/
SRC = $(addprefix $(SRC_PREFIX), main.c utils.c)

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

RM = rm -f

all:	$(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) 

$(LIBFT):
	make -C ./libft

clean:
	$(RM) $(OBJ) $(LIBFT)
	make clean -C libft

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)