NAME 	= procedure

SRC 	= main.cpp Bureaucrat.cpp Form.cpp
HEADER	= Bureaucrat.h Form.h

CC 		= c++
FLAGS	= -Wall -Wextra -Werror -g -std=c++98 -fsanitize=address
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
