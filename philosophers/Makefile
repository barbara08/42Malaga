NAME = philo

SRC = main.c 

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)
	@echo "$(NAME) CREATED!"

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
