NAME = libft.a

SRC = ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_strlcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_strtrim.c \
ft_strjoin.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \

OBJ = $(SRC:.c=.o)

HEADER = libft.h

CFLAGS = -Wall -Werror -Wextra

CC = gcc

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	@echo "$(NAME) Created Successfully "

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo "Deleted Object Files "

fclean: clean
	rm -f $(NAME)
	@echo "Deleted Library"

re: fclean all

.PHONY: all clean fclean re
