NAME 	= procedure

SRC 	= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
HEADER	= Bureaucrat.h AForm.h ShrubberyCreationForm.h RobotomyRequestForm.h PresidentialPardonForm.h Intern.h

CC 		= c++
FLAGS	= -Wall -Wextra -Werror -g -std=c++98 -fsanitize=address
RM		= rm -rf

all: $(NAME)

$(NAME):	$(SRC) $(HEADER)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	@$(RM) $(NAME) **_shrubbery

fclean:
	@$(RM) $(NAME) **_shrubbery

re: fclean all

.PHONY: all clean fclean re
