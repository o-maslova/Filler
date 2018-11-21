/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <omaslova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:44:18 by omaslova          #+#    #+#             */
/*   Updated: 2018/11/21 17:44:22 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	find_min_distance(t_data *data, int dotrow, int dotcol)
{
	int i;
	int j;
	int dist;

	i = 0;
	while (i < ROW)
	{
		j = 0;
		while (j < COLUMN)
		{
			dist = ABS(dotrow - i) + ABS(dotcol - j);
			if (data->mtrx[i][j].is_enemy &&
				dist < data->mtrx[dotrow][dotcol].length)
			{
				data->mtrx[dotrow][dotcol].length = dist;
			}
			++j;
		}
		++i;
	}
}

void	set_distance(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < ROW)
	{
		j = 0;
		while (j < COLUMN)
		{
			find_min_distance(data, i, j);
			++j;
		}
		++i;
	}
}

void	get_data(char **line, t_data *data)
{
	char		*ptr;
	t_coords	*list;

	list = NULL;
	if ((ptr = ft_strstr(*line, "[./omaslova.filler]")))
	{
		PLAYER = *(ptr - 4) == '1' ? 'o' + 100 : 'x' + 100;
		ENEMY = PLAYER == 'o' + 100 ? 'x' + 100 : 'o' + 100;
	}
	else if ((ptr = ft_strstr(*line, "Plateau")))
		set_data(line, data);
	else if ((ptr = ft_strstr(*line, "Piece")))
	{
		get_pc(ptr + 6, data);
		set_distance(data);
		search_position(data, &list);
		ft_printf("%d %d\n", data->coords->x, data->coords->y);
		ft_arrdel(data->pc, data->x_pc);
		clear_list(list);
	}
}

int		main(void)
{
	int			i;
	char		*line;
	t_data		*data;

	data = (t_data *)ft_memalloc(sizeof(t_data));
	data->coords = (t_coords *)ft_memalloc(sizeof(t_coords));
	i = 0;
	while (get_next_line(0, &line))
	{
		if (i < ROW && !(ft_strstr(line, "Plateau")))
			i = set_mtrx(line + 4, data, i);
		else
		{
			get_data(&line, data);
			clear_mtrx(data, &i);
		}
		free(line);
	}
	free(data->coords);
	ft_mtrxdel(data->mtrx, ROW);
	free(data);
	return (0);
}
