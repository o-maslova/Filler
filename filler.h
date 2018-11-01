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
# include "libft/libft.h"

typedef struct		s_data
{
	int				row;
	int				column;
	unsigned char	player;
	unsigned char	**mtrx;
	char			**pc;
	int				x_pc;
	int				y_pc;
	int				my_pos[4];
	int				en_pos[2];
	int				X;
	int				Y;
}					t_data;

typedef struct		s_check
{
	int				i;
	int				j;
	int				i_pc;
	int				j_pc;
	int				check;
}					t_check;

void				define_coords(t_data *data);
int					change_coords(t_data *data, char enemy);
void				search_position(t_data *data);
void				print_mtrx(t_data *data);

#endif