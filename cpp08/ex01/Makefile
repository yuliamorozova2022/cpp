NAME 	= span

SRC 	= main.cpp Span.cpp
HEADER	= Span.h

CC 		= c++
FLAGS	= -Wall -Wextra -Werror -g -std=c++98 -fsanitize=address #-std=c++11
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