NAME = philo

SRC = main.c parse.c init.c time.c routines.c monitor.c actions.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)
	@echo "$(NAME) CREATED!"

%.o: %.c philo.h structs.h
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

