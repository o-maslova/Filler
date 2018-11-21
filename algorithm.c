/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <omaslova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:46:16 by omaslova          #+#    #+#             */
/*   Updated: 2018/11/21 17:46:19 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		set_return_coords(t_data *data, int x, int y)
{
	data->coords->x = x;
	data->coords->y = y;
}

void		find_first_col(t_data *data)
{
	int i;
	int j;

	i = 0;
	data->star_row = data->x_pc;
	data->star_col = data->y_pc;
	while (i < data->x_pc)
	{
		j = 0;
		while (j < data->y_pc)
		{
			if (data->pc[i][j] == '*')
			{
				if (j < data->star_col)
					data->star_col = j;
				if (i < data->star_row)
					data->star_row = i;
			}
			++j;
		}
		++i;
	}
}

int			check_conditions(t_data *data, int i, int row, int col)
{
	int j;
	int res;

	res = 0;
	j = data->star_col;
	while (j < data->y_pc)
	{
		if (data->pc[i][j] == '*')
		{
			if (row >= ROW || col >= COLUMN)
				return (-1);
			if (data->mtrx[row][col].is_enemy)
				return (-1);
			if (data->mtrx[row][col].is_player)
			{
				data->star_amount += 1;
				if (data->star_amount > 1)
					return (-1);
			}
			res += data->mtrx[row][col].length;
		}
		++col;
		++j;
	}
	return (res);
}

int			algorithm(t_data *data, int row, int col)
{
	int i;
	int res;
	int temp;

	res = 0;
	i = data->star_row;
	data->star_amount = 0;
	while (i < data->x_pc)
	{
		if ((temp = check_conditions(data, i, row, col)) == -1)
			return (0);
		res += temp;
		++row;
		++i;
	}
	if (data->star_amount == 0)
		res = 0;
	return (res);
}

void		search_position(t_data *data, t_coords **list)
{
	int			i;
	int			j;
	int			tmp;
	t_coords	*new;

	i = -1;
	new = NULL;
	find_first_col(data);
	while (++i < ROW)
	{
		j = -1;
		while (++j < COLUMN)
			if ((tmp = algorithm(data, i, j)) > 0)
			{
				new = node_create(i - data->star_row, j - data->star_col, tmp);
				add_node(list, new);
			}
	}
	if (!(*list))
		set_return_coords(data, 0, 0);
	else
	{
		*list = sort_list(*list);
		set_return_coords(data, (*list)->x, (*list)->y);
	}
}
