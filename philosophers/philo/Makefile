NAME = philo

SRC = main.c parse.c init.c time.c routines.c monitor.c actions.c

OBJ = $(SRC:.c=.o)

#Para compilar en Linux
#CC = cc
#CFLAGS  = -Wall -Wextra -Werror

#Para compilar en Mac (ASAN)
CC      = clang
CFLAGS  = -Wall -Wextra -Werror -g \
		  -fsanitize=address -O1 -fno-omit-frame-pointer

#Para detectar Data Races (TSAN)
#CFLAGS  = -Wall -Wextra -Werror -fsanitize=thread -g3 -pthread
#LDFLAGS = -fsanitize=thread -pthread

all: $(NAME)

#OJO solo modicar esta linea =>	$(CC) $(LDFLAGS) $(OBJ) -o $(NAME) => Cuando usemos TSAN (LDFLAGS)
# Por esta => 					$(CC) $(CFLAGS) $(OBJ) -o $(NAME) => Para compilar en Linnux o en Mac (ASAN) (CFLAGS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
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

