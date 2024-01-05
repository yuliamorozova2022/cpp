NAME =	phonebook

SRC =	phonebook.cpp contacts.cpp
HEADER = phonebook.hpp

CC =	c++
FLAGS =	-Wall -Wextra -Werror -std=c++98 -g
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
