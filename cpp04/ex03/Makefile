NAME 	= materias

SRC 	= main.cpp AMateria.cpp Cure.cpp Ice.cpp Character.cpp MateriaSource.cpp
HEADER	= AMateria.h Cure.h Ice.h ICharacter.h Character.h IMateriaSource.h MateriaSource.h

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
