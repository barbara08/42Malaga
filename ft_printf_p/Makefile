CC = cc

CFLAGS = -Wall -Wextra -Werror 

NAME = libftprintf.a

SRC = ft_converse_base.c \
ft_count_caracter.c \
ft_count_digit.c \
ft_format.c \
ft_format_int.c \
ft_itoa.c \
ft_printf.c \
ft_putchar.c \
ft_putstr.c \

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

execute: 
	@$(CC) $(CFLAGS) *.c
	@./a.out

%.o: %.c printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
