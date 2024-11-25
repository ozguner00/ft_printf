NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

SRCS = ft_printf.c ft_printf_utils.c ft_printf_put_func2.c  ft_printf_put_func.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean  