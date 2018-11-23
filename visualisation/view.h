#ifndef VIEW_H
# define VIEW_H

# include <stdio.h>
# include <mlx.h>
# include "../filler.h"

# define WIDTH 1000
# define HEIGTH 1000
# define VIEW_ROW win->row
# define VIEW_COLUMN win->column
# define CELL_SIZE 48
# define PAD 100

int		g_fd;
int		g_fd_m;
char	g_player;
char	g_enemy;

typedef struct		s_win
{
	int				row;
	int				column;
	int				x_pc;
	int				y_pc;
	char			*img;
	char			**matrix;
	char			**pc;
	void			*img_ptr;
	void			*win_ptr;
	void			*mlx_ptr;
}					t_win;

void				draw_field(t_win *win);
void				draw_players(t_win *win);
void				draw_matrix(t_win *win);
void				display_winner(t_win *win, char *line);

#endif