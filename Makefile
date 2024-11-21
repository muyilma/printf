NAME=libftprintf.a

SRC=ft_printf_list.c ft_printf.c 

OBJS=${SRC:.c=.o}

CFLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re