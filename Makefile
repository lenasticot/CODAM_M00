NAME = libftprintf.a
SRCS = count_nbr.c \
ft_strlen.c \
ft_hexa.c \
count_hex_digits.c \
ft_pointer.c \
ft_putchar.c \
ft_putnbr.c \
ft_unsigned_putnbr.c \
whatisthis.c \
main.c \
ft_printf.c \
ft_putstr.c \
ft_whatisthat.c \

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o test_printf
	./test_printf
	rm test_printf

.PHONY: all clean fclean re