NAME = push_swap

SRC = rules_push.c \
rules_reverse_rotate.c \
rules_rotate.c \
rules_swap.c \
aux_sort.c \
aux_big_sort.c \
libft.c \
parsing.c \
utils.c \
sorted.c \
main.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re