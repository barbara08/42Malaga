NAME = so_long

SRC = main.c window.c aux.c validate_map.c map.c draw_map.c textures.c movements.c ft_flood_fill.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c \
	libft/ft_strdup.c libft/ft_memcpy.c libft/ft_putnbr_fd.c \

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -I./gnl -I./libft -I./minilibx-linux
LDFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)
	@echo "$(NAME) CREATED!"

%.o: %.c so_long.h structs.h
	$(CC) $(CFLAGS) -c $< -o $@

#ADDED RULE: For files inside libft/
libft/%.o: libft/%.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

#ADDED RULE: For files inside gnl/
gnl/%.o: gnl/%.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

