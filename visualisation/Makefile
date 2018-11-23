NAME = omaslova.visualisation
LIB = libft.a
GRAPHICS = -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
SRC = ./main.c ./visualisation.c ./display_staff.c
BINS = $(SRC:.c=.o)
HEADER = ./view.h ../filler.h
LIB_DIR = ../libft/
LFT = $(addprefix $(LIB_DIR), $(LIB))

all: $(NAME)

$(NAME): $(BINS)
	gcc -o $(NAME) $(LFT) $(BINS) $(GRAPHICS)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -o $@ -c $< -I $(LFT)

clean:
	/bin/rm -f $(BINS)
	/bin/rm -f *~

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all