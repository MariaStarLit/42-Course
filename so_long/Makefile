NAME = so_long

NAME_BONUS = so_long_bonus

SRC_PREFIX = ./source/
BONUS_PREFIX = ./bonus/

SRC = $(addprefix $(SRC_PREFIX), main.c get_next_line.c check_map.c  \
		check_path.c draw_map.c draw_map_2.c utils.c hooks.c exit_game.c)

BONUS = $(addprefix $(BONUS_PREFIX), main_bonus.c get_next_line_bonus.c \
		check_map_bonus.c check_path_bonus.c draw_map_bonus.c draw_map2_bonus.c \
		utils_bonus.c hooks_bonus.c exit_game_bonus.c)

OBJ = $(SRC:.c=.o)
B_OBJ = $(BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address

LIBFT = ./libft/libft.a
MLX = ./mlx_linux/libmlx_Linux.a

LINKS = $(LIBFT) $(MLX) -lXext -lX11 -lm -lz

RM = rm -f

all: $(NAME)

bonus:  $(NAME_BONUS)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LINKS)

$(NAME_BONUS): $(B_OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(B_OBJ) -o $(NAME_BONUS) $(LINKS)

$(LIBFT):
	make -C ./libft

$(MLX):
	make -C ./mlx_linux

clean:
	$(RM) $(OBJ) $(B_OBJ) $(LIBFT) $(MLX)
	make clean -C libft
	make clean -C mlx_linux 

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)  

re: fclean $(NAME) $(NAME_BONUS)
