NAME = so_long

SRC = main.c

OBJ = $(SRC:.c=.o)

CC = cc

#Para MacOS
#CFLAGS = -Wall -Wextra -Werror -Iminilibx_opengl_20191021
#LDFLAGS = -Lminilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

#Para Linux
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux
LDFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
