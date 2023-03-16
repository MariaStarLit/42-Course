# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 14:42:17 by mde-avel          #+#    #+#              #
#    Updated: 2023/03/08 18:10:22 by mde-avel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = pipex.c

LIBFT = ft_putstr_fd.c ft_putchar_fd.c ft_split.c ft_strlen.c
			
OBJ = $(SRC:.c=.o)

LOBJ = $(LIBFT:.c=.o)

PRELB = libft/

all:	$(NAME)

$(NAME):	$(OBJ) $(addprefix $(PRELB),$(LOBJ))
			ar rcs $(NAME) $(OBJ) $(addprefix $(PRELB),$(LOBJ))

clean:
			$(RM) $(OBJ) $(addprefix $(PRELB),$(LOBJ))

fclean:	clean
			$(RM) $(NAME)

re:	fclean $(NAME)