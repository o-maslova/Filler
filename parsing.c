/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <omaslova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:52:24 by omaslova          #+#    #+#             */
/*   Updated: 2018/11/21 14:52:27 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		set_mtrx(char *line, t_data *data, int i)
{
	int j;

	j = 0;
	while (j < COLUMN)
	{
		line[j] = ft_tolower(line[j]);
		data->mtrx[i][j].length = 255;
		if (line[j] + 100 == PLAYER)
			data->mtrx[i][j].is_player = 1;
		if (line[j] + 100 == ENEMY)
			data->mtrx[i][j].is_enemy = 1;
		++j;
	}
	return (++i);
}

void	memory_allocate(char *line, t_data *data)
{
	int i;

	i = 0;
	line += 8;
	ROW = ft_atoi(line);
	line += ft_digitnum(ROW);
	COLUMN = ft_atoi(line);
	data->mtrx = (t_point **)ft_memalloc(sizeof(t_point *) * ROW);
	while (i < ROW)
		data->mtrx[i++] = (t_point *)ft_memalloc(sizeof(t_point) * COLUMN);
}

void	set_data(char **line, t_data *data)
{
	static int i;

	if (i == 0)
	{
		memory_allocate(*line, data);
		++i;
	}
	free(*line);
	get_next_line(0, line);
}

void	get_pc(char *str, t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	data->x_pc = ft_atoi(str);
	data->y_pc = ft_atoi(str + ft_digitnum(data->x_pc));
	data->pc = (char **)ft_memalloc(sizeof(char *) * data->x_pc);
	while (i < data->x_pc)
	{
		get_next_line(0, &line);
		data->pc[i] = (char *)ft_memalloc(sizeof(char) * data->y_pc);
		data->pc[i] = ft_strncpy(data->pc[i], line, data->y_pc);
		i++;
		free(line);
	}
}
