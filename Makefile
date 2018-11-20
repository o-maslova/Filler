NAME = omaslova.filler
LIB = ./ft_printf/libftprintf.a ./ft_printf/libft/libft.a
FLAGS = -Wall -Wextra -Werror
SRC = ./algorithm.c ./parsing.c ./main.c ./list_staff.c
BINS = $(SRC:.c=.o)
HEADER = ./filler.h

all: lib $(NAME)

lib:
	make -C ft_printf

$(NAME): $(BINS) $(LIB)
	gcc -o $(NAME) $(BINS) $(LIB)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -o $@ -c $< -I ft_printf

clean:
	make clean -C ft_printf
	/bin/rm -f $(BINS)
	/bin/rm -f *~

fclean: clean
	make fclean -C ft_printf
	/bin/rm -f $(NAME)

re: fclean all