NAME = so_long

SRC = main.c window.c map.c draw_map.c textures.c movements.c\
      gnl/get_next_line.c gnl/get_next_line_utils.c \
      libft/ft_strlen.c libft/ft_strdup.c

OBJ = $(SRC:.c=.o)

CC = cc


#Para MacOS
#CFLAGS = -Wall -Wextra -Werror -Iminilibx_opengl_20191021
#LDFLAGS = -Lminilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

# Para Linux
CFLAGS = -Wall -Wextra -Werror -I./gnl -I./libft -I./minilibx-linux
LDFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)
	@echo "$(NAME) CREATED!"

# Regla genérica (para archivos en el directorio actual)
%.o: %.c so_long.h 
	$(CC) $(CFLAGS) -c $< -o $@

# REGLA AÑADIDA: Para archivos dentro de libft/
libft/%.o: libft/%.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

# REGLA AÑADIDA: Para archivos dentro de gnl/
gnl/%.o: gnl/%.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

