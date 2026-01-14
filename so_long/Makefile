NAME = so_long

SRC = main.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Iminilibx_opengl_20191021 -Lminilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit 

CC = cc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re