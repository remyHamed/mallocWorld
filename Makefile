CC = gcc
RM = rm -f
NAME = mallocworld
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -lm -o $(NAME) -Werror
	$(RM) $(OBJS)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re