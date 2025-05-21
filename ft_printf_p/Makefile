#Declarar las variables
CC = cc

CFLAGS = -Wall -Wextra -Werror 

NAME = printf.a

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

# Regla para generar la libreria estatica .a usando ar y ranlib
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

#para que genere el ./a.out
execute: 
	$(CC) $(CFLAGS) *.c
	./a.out

# VER   Las dos siguientes lineas no hace falta 
# $(NAME): $(OBJ)
#	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

#Definir el comando a ejecutar
%.o: %.c printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
