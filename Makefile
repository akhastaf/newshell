C = gcc
FLAGS = -Wall -Wextra -Werror
NAME = minishell
D = -g
SRC = ./src/*.c ./src/*/*.c
OBJ = minishell

all: $(NAME)

$(NAME):
	@$(C) -g -o $(NAME) main.c $(SRC)

debug:
	@$(C) -g -o $(NAME) main.c $(SRC) -fsanitize=address

clean:
	@rm -f $(NAME)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all