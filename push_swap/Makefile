# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 16:59:58 by mde-avel          #+#    #+#              #
#    Updated: 2023/08/10 17:13:15 by mde-avel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g  #-fsanitize=address

RM = rm -f

SRCS = checks.c moves_1.c moves_2.c moves_3.c push_swap.c sort_big.c sort_small.c utils.c \
		ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_puthex.c ft_printf/ft_putnbr.c ft_printf/ft_putnbru.c ft_printf/ft_putstr.c ft_printf/ft_putvod.c \
		libft/libft_1.c libft/libft_2.c libft/libft_3.c

OBJ = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) $(NAME)

re:	fclean $(NAME)