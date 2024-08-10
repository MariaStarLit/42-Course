NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRC =  check_map.c colors.c exit.c main.c parsing.c utils.c walls.c game.c movement.c raycasting.c image.c init.c
SRCS =	$(addprefix src/, $(SRC))

OBJ_DIR = obj
OBJS =	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

libmlx = minilibx-linux
MLX = $(libmlx)/libmlx.a
lib = libft
LIB = $(lib)/libft.a

LINKS = $(LIB) $(MLX) -lXext -lX11 -lm -lz

# Colors
Color_Off='\033[0m'       # Reset
IGreen='\033[0;92m'       # Green
IYellow='\033[0;93m'      # Yellow

MSG1 = @echo ${IGreen}"Compiled Successfully ✔︎"${Color_Off}
MSG2 = @echo ${IYellow}"Cleaned Successfully ✔︎"${Color_Off}

CLEAR = clear -x # This cleanS the terminal without deleting everything just pussing up

all: $(NAME)

$(LIB):
	@make -s -C $(lib)
$(MLX):
	@make -s -C $(libmlx)

$(NAME): $(LIB) $(MLX) $(OBJS)
	@$(CLEAR)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LINKS)
	$(MSG1)

$(OBJ_DIR)/%.o: $(SRCS)
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(CLEAR)
	@/bin/rm -rf $(OBJ_DIR)
	@make clean --no-print-directory -C $(lib)
	@make clean --no-print-directory -C $(libmlx)
	$(MSG2)

fclean: clean
	@/bin/rm -rf $(NAME) ${OBJ_DIR} $(LIB) $(MLX)


re: fclean all

v:
	@valgrind -s --track-fds=yes --leak-check=full --show-leak-kinds=all --log-file="val_log.txt" ./cub3D maps/map2.cub