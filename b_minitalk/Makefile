NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = server.c
SRC_CLIENT = client.c
SRC_UTILS = utils.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_UTILS = $(SRC_UTILS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER) $(OBJ_UTILS)
	@$(CC) $(CFLAGS) $(SRC_SERVER) $(SRC_UTILS) -o $(NAME_SERVER)
	@echo "$(NAME_SERVER) CREATED!"

$(NAME_CLIENT): $(OBJ_CLIENT) $(OBJ_UTILS)
	@$(CC) $(CFLAGS) $(SRC_CLIENT) $(SRC_UTILS) -o $(NAME_CLIENT)
	@echo "$(NAME_CLIENT) CREATED!"

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_UTILS)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re