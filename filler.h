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
# define ABS(x) ((x) > 0 ? (x) : -(x))
# define PLAYER data->player
# define ENEMY data->enemy
# include "libft/libft.h"
#include <stdio.h>

typedef struct		s_point
{
	unsigned char	length;
	int				isPlayer;
	int				isEnemy;
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
	t_coords		*coords;
}					t_data;

int					down(t_data *data, int row, int col, int res);
void				star_min_dist(t_data *data, int row, int col, t_coords **nw);
void				search_position(t_data *data, t_coords *list);
int					set_mtrx(char *line, t_data *data, int i);
void				set_data(char *line, t_data *data);
void				get_pc(char *str, t_data *data, int fd);


#endif