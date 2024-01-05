NAME 	= animals

SRC 	= main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp#WrongAnimal.cpp WrongCat.cpp
HEADER	= Animal.h Cat.h Dog.h Brain.h#WrongAnimal.h WrongCat.h

CC 		= c++
FLAGS	= -Wall -Wextra -Werror -g -std=c++98 #-fsanitize=address
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
