# -*- MakeFile -*-

CC = @cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_base.c \
		ft_options.c \
		ft_printchar.c \
		ft_printf.c \
		ft_printnbr.c \
		ft_print_ptr.c \
		ft_printstr.c \
		ft_strcmp.c \
		ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \

OBJ = $(SRC:.c=.o)

MSG1 = @echo "\e[1;32m Compiled ${NAME} Successfully ✔︎ \e[0m"
MSG2 = @echo "\033[93m Cleaned ${NAME} Successfully ✔︎ \e[0m"

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	$(MSG1)

clean:
	@/bin/rm -f $(OBJ)
	$(MSG2)

fclean: clean
	@/bin/rm -f $(NAME)
#	$(MSG2)

re: fclean all