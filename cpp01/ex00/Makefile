NAME 	= zombie

SRC 	= main.cpp Zombie.cpp randomChump.cpp newZombie.cpp
HEADER	= Zombie.h

CC 		= c++
FLAGS	= -Wall -Wextra -Werror -g -std=c++98 
RM		= rm -rf

all: $(NAME)

$(NAME):	$(SRC) $(HEADER)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	@$(RM) $(NAME)

fclean:
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re