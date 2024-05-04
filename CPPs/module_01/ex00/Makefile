NAME = BraiiiiiiinnnzzzZ

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RM = @/bin/rm -rf

SRC =  main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

# OBJ_DIR = obj
# OBJS =	$(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))
OBJS =	$(SRC:%.cpp=%.o)

# Colors
Color_Off='\033[0m'       # Reset
IGreen='\033[0;92m'       # Green
IYellow='\033[0;93m'      # Yellow

MSG1 = @echo ${IGreen}"Compiled SucXXessfully ✔︎"${Color_Off}
MSG2 = @echo ${IYellow}"Cleaned SucXXessfully ✔︎"${Color_Off}

#CLEAR = clear -x # This cleanS the terminal without deleting everything just pussing up

all: $(NAME)

$(NAME): $(OBJS)
#	@$(CLEAR)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)
	$(MSG1)

# $(OBJ_DIR)/%.o: $(SRC)
# 		@mkdir -p $(OBJ_DIR)
# 		@$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
#	@$(CLEAR)
	$(RM) $(OBJS)
	$(MSG2)

fclean: clean
	$(RM) $(NAME)

re: fclean all

v:
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --log-file="val_log.txt" ./BraiiiiiiinnnzzzZ