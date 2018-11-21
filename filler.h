/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <omaslova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 12:23:13 by omaslova          #+#    #+#             */
/*   Updated: 2018/10/16 12:23:15 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "./ft_printf/ft_printf.h"
# define ABS(x) ((x) >= 0 ? (x) : -(x))
# define PLAYER data->player
# define ENEMY data->enemy
# define ROW data->row
# define COLUMN data->column

typedef struct		s_point
{
	unsigned char	length;
	int				is_player;
	int				is_enemy;
}					t_point;

typedef struct		s_coords
{
	int				x;
	int				y;
	int				sum;
	struct s_coords	*next;
}					t_coords;

typedef struct		s_data
{
	int				row;
	int				column;
	unsigned char	player;
	unsigned char	enemy;
	t_point			**mtrx;
	char			**pc;
	int				x_pc;
	int				y_pc;
	int				star_row;
	int				star_col;
	int				star_amount;
	t_coords		*coords;
}					t_data;

void				search_position(t_data *data, t_coords **list);
int					set_mtrx(char *line, t_data *data, int i);
void				set_data(char **line, t_data *data);
void				get_pc(char *str, t_data *data);
void				clear_list(t_coords *list);
void				clear_mtrx(t_data *data, int *counter);
void				ft_mtrxdel(t_point **arr, int row);
void				add_node(t_coords **list, t_coords *new_node);
t_coords			*sort_list(t_coords *list);
t_coords			*node_create(int x, int y, int sum);

#endif
