# -*- MakeFile -*-

NAME = minishell

CC = @cc
CFLAGS = -Wall -Wextra -Werror -g 

# -fsanitize=address
# -fsanitize=thread

SRC =	main.c prompt.c frees.c signals.c
SRC_builtin = cd.c echo.c env.c exit.c export.c pwd.c unset.c builtin_utils.c 
SRC_pipex = exec_utils.c exec.c hdoc_utils.c heredoc.c ms_pipex.c redirects.c
SRC_parser = ms_split.c parser_utils.c
SRC_replacer = replace_utils.c replace.c
SRC_syntax = syntax_err.c syntax.c
SRC_utils = arr_utils.c check_cmd.c cmd_utils.c cmd_utils2.c error.c error1.c free2.c inits.c quotes_utils.c str_utils.c

lib = libft
LIB = $(lib)/libft.a

OBJ_DIR = obj

SRCS =	$(addprefix src/, $(SRC)) $(addprefix src/Parser/, $(SRC_parser)) $(addprefix src/Utils/, $(SRC_utils)) \
		$(addprefix src/BuiltIn/, $(SRC_builtin)) $(addprefix src/replacer/, $(SRC_replacer)) \
		$(addprefix src/ms_pipex/, $(SRC_pipex)) $(addprefix src/syntax/, $(SRC_syntax))

OBJS =	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o)) $(addprefix $(OBJ_DIR)/, $(SRC_parser:%.c=%.o)) \
		$(addprefix $(OBJ_DIR)/, $(SRC_utils:%.c=%.o)) $(addprefix $(OBJ_DIR)/, $(SRC_builtin:%.c=%.o)) \
		$(addprefix $(OBJ_DIR)/, $(SRC_replacer:%.c=%.o)) $(addprefix $(OBJ_DIR)/, $(SRC_pipex:%.c=%.o)) \
		$(addprefix $(OBJ_DIR)/, $(SRC_syntax:%.c=%.o))

# Reset
Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White

# Underline
UBlack='\033[4;30m'       # Black
URed='\033[4;31m'         # Red
UGreen='\033[4;32m'       # Green
UYellow='\033[4;33m'      # Yellow
UBlue='\033[4;34m'        # Blue
UPurple='\033[4;35m'      # Purple
UCyan='\033[4;36m'        # Cyan
UWhite='\033[4;37m'       # White

# Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White

# High Intensity
IBlack='\033[0;90m'       # Black
IRed='\033[0;91m'         # Red
IGreen='\033[0;92m'       # Green
IYellow='\033[0;93m'      # Yellow
IBlue='\033[0;94m'        # Blue
IPurple='\033[0;95m'      # Purple
ICyan='\033[0;96m'        # Cyan
IWhite='\033[0;97m'       # White

# Bold High Intensity
BIBlack='\033[1;90m'      # Black
BIRed='\033[1;91m'        # Red
BIGreen='\033[1;92m'      # Green
BIYellow='\033[1;93m'     # Yellow
BIBlue='\033[1;94m'       # Blue
BIPurple='\033[1;95m'     # Purple
BICyan='\033[1;96m'       # Cyan
BIWhite='\033[1;97m'      # White

# High Intensity backgrounds
On_IBlack='\033[0;100m'   # Black
On_IRed='\033[0;101m'     # Red
On_IGreen='\033[0;102m'   # Green
On_IYellow='\033[0;103m'  # Yellow
On_IBlue='\033[0;104m'    # Blue
On_IPurple='\033[0;105m'  # Purple
On_ICyan='\033[0;106m'    # Cyan
On_IWhite='\033[0;107m'   # White

MSG1 = @echo ${IGreen}"Compiled Successfully ✔︎"${Color_Off}
MSG2 = @echo ${IYellow}"Cleaned Successfully ✔︎"${Color_Off}
MSG3 = @echo ${ICyan}"Cleaned ${NAME} Successfully ✔︎"${Color_Off}
HOWTO = @echo ${IRed}"To run the program do: ./${NAME}"${Color_Off}

CTRL_L = clear -x # This is the same as CTRL + L cleaning the terminal without deleting everything just pussing up

all: $(NAME)

$(LIB):
	@make -s -C $(lib)

$(NAME): $(LIB) $(OBJS)
	@$(CTRL_L)
	@$(CC) $(CFLAGS) $(SRCS) -lreadline $(LIB) -o $(NAME)
	$(MSG1)
	${HOWTO}

$(OBJ_DIR)/%.o: $(SRCS)
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) -o $@ -c $<

a: all
	@$(CTRL_L)

clean:
	@$(CTRL_L)
	@/bin/rm -rf $(OBJ_DIR)
	@make clean --no-print-directory -C $(lib)
	$(MSG2)

fclean: clean
	@/bin/rm -rf $(NAME) ${OBJ_DIR} $(LIB)
	$(MSG3)

re: fclean all

val:
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --suppressions=readline.supp --log-file="val_log.txt" ./minishell
# --trace-children=yes
