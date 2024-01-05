NAME 	= frag

SRC 	= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
HEADERS	= ClapTrap.h ScavTrap.h FragTrap.h

CC 		= c++
FLAGS	= -Wall -Wextra -Werror -g -std=c++98 
RM		= rm -rf

all: $(NAME)

$(NAME):	$(SRC) $(HEADERS)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	@$(RM) $(NAME)

fclean:
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
