NAME = libftprintf.a

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

CC = cc

SRC = ft_converse_base.c \
ft_count_caracter.c \
ft_count_digit.c \
ft_format.c \
ft_format_int.c \
ft_itoa.c \
ft_printf.c \
ft_putchar.c \
ft_putstr.c \
ft_putnbr.c \

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

#execute: 
#	@$(CC) $(CFLAGS) *.c
#	@./a.out

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
