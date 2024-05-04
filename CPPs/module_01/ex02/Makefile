NAME = hiThisIsBrain

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RM = @/bin/rm -rf

SRC =  main.cpp

OBJS =	$(SRC:%.cpp=%.o)

# Colors
Color_Off='\033[0m'       # Reset
IGreen='\033[0;92m'       # Green
IYellow='\033[0;93m'      # Yellow

MSG1 = @echo ${IGreen}"Compiled Successfully ✔︎"${Color_Off}
MSG2 = @echo ${IYellow}"Cleaned Successfully ✔︎"${Color_Off}

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)
	$(MSG1)

clean:
	$(RM) $(OBJS)
	$(MSG2)

fclean: clean
	$(RM) $(NAME)

re: fclean all

v:
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --log-file="val_log.txt" ./hiThisIsBrain