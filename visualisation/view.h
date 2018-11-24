/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <omaslova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:08:46 by omaslova          #+#    #+#             */
/*   Updated: 2018/11/24 14:08:53 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

# include <stdio.h>
# include <mlx.h>
# include "../filler.h"

# define WIDTH win->width
# define HEIGTH win->heigth
# define VIEW_ROW win->row
# define VIEW_COLUMN win->column
# define CELL_SIZE win->cell
# define PAD (win->value + CELL_SIZE)
# define POSITION (win->column * (win->cell / 2))
# define VAL win->value

int		g_fd;
int		g_fd_m;
char	g_player;
char	g_enemy;

typedef struct		s_win
{
	int				width;
	int				heigth;
	int				row;
	int				column;
	int				cell;
	int				value;
	int				my_score;
	int				enemy_score;
	int				size_line;
	int				endian;
	int				bpp;
	char			*img;
	char			**matrix;
	char			**pc;
	void			*win_ptr;
	void			*mlx_ptr;
	void			*img_ptr;
}					t_win;

int					allocate_mem(t_win *win, char *line, int i);
int					set_matrix(t_win *win);
void				init(t_win *win);
void				define_values(t_win *win);
void				draw_field(t_win *win);
void				draw_players(t_win *win);
void				display_winner(t_win *win, char *line);

#endif
