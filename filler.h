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
# include <signal.h>

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

void				define_coords(t_data *data);
int					change_coords(t_data *data, char enemy);
void				search_position(t_data *data);
void				print_mtrx(t_data *data);

#endif