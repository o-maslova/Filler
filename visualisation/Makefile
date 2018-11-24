NAME = omaslova.visualisation
LIB = libft.a
GRAPHICS = -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
SRC = ./main.c ./visualisation.c ./display_staff.c ./define_values.c
BINS = $(SRC:.c=.o)
HEADER = ./view.h ../filler.h
LIB_DIR = ../libft/
EXE_DIR = ../
LFT = $(addprefix $(LIB_DIR), $(LIB))
EXE = $(addprefix $(EXE_DIR), $(NAME))

all: $(EXE)

$(EXE): $(BINS)
	gcc -o $(EXE) $(LFT) $(BINS) $(GRAPHICS)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -o $@ -c $< -I $(LFT)

clean:
	/bin/rm -f $(BINS)
	/bin/rm -f *~

fclean: clean
	/bin/rm -f $(EXE)

re: fclean all