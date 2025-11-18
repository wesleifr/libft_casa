NAME	= libft.a

SRC_DIR	= srcs
SRCS	= $(wildcard $(SRC_DIR)/*.c)
OBJS	= $(SRCS:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I includes
AR		= ar rcs
RM		= rm -f

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra opcional para testar a biblioteca
test: $(NAME)
	$(CC) $(CFLAGS) main.c -L. -lft -o test

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) test test.exe

re: fclean all
