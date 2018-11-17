NAME = omaslova.filler
LIB = ./libft/libft.a
FLAGS = -c -Wall -Wextra -Werror
SRC = ./algorithm.c ./parsing.c ./main.c
BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	make -C libft
	gcc -o $(NAME) $(BINS) $(LIB)

%.o : %.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	make clean -C libft
	/bin/rm -f $(BINS)
	/bin/rm -f *~

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all