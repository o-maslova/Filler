NAME = omaslova.filler
LIB = ./libft/libft.a
FLAGS = -g -Wall -Wextra -Werror
SRC = ./algorithm.c ./parsing.c ./main.c ./list_staff.c
BINS = $(SRC:.c=.o)
HEADER = ./filler.h

all: lib $(NAME)

lib:
	make -C libft

$(NAME): $(BINS) $(LIB)
	gcc -o $(NAME) $(BINS) $(LIB)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -o $@ -c $< -I libft

clean:
	make clean -C libft
	/bin/rm -f $(BINS)
	/bin/rm -f *~

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all