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
	unsigned char	**matrix;
	char			**piece;
	int				x_piece;
	int				y_piece;
	int				my_pos[4];
	int				en_pos[2];
	int				X;
	int				Y;
}					t_data;

#endif