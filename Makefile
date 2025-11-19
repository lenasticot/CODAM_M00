NAME = libftprintf.a
SRCS = ft_strlen.c \
ft_hexa_upper.c \
count_hex_digits.c \
ft_pointer.c \
ft_putchar.c \
ft_putnbr.c \
ft_unsigned_putnbr.c \
whatisthis.c \
ft_printf.c \
ft_putstr.c \
ft_whatisthat.c \
ft_hexa_lower.c \
ft_strdup.c \
ft_calloc.c \

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

.PHONY: all clean fclean re