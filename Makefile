NAME = omaslova.filler

# HEADER = ./fillit.h

FLAGS = -c -Wall -Wextra -Werror

# SRC = ./algorithm.c ./validation.c ./make_list.c ./main.c

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	gcc -o $(NAME) $(BINS)

%.o : %.c $(HEADER)
	gcc $(FLAGS) -o $@ $<

clean:
	/bin/rm -f $(BINS)
	/bin/rm -f *~

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all