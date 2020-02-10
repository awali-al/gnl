NAME = libft.a
SRCS = *.c
OBJS = *.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): 
	gcc -c $(FLAGS) $(SRCS) 
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
