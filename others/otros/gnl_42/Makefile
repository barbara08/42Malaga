NAME = gnl.a

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

CC = cc

SRC = get_next_line_utils.c\
	get_next_line.c \

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

execute: 
	@$(CC) $(CFLAGS) *.c
	@./a.out

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re