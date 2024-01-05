NAME 	= smth

SRC 	= main.cpp 

CC 		= c++
FLAGS	= -Wall -Wextra -Werror -g -std=c++98 
RM		= rm -rf

all: $(NAME)

$(NAME):	$(SRC) 
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	@$(RM) $(NAME)

fclean:
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re