#include "filler.h"

int		set_mtrx(char *line, t_data *data, int i)
{
	int j;
	
	j = 0;
	while (j < data->column)
	{
		*line = ft_tolower(*line);
		data->mtrx[i][j].length = 255;//(unsigned char)*line++;
		if (*line + 100 == data->player)
			data->mtrx[i][j].isPlayer = 1;
		else if (*line + 100 == data->enemy)
			data->mtrx[i][j].isEnemy = 1;
		++line;
		++j;
	}
	return (++i);
}

void	set_data(char *line, t_data *data)
{
	int i;

	i = 0;
	line += 8;
	data->row = ft_atoi(line);
	line += ft_digitnum(data->row);
	data->column = ft_atoi(line);
	data->mtrx = (t_point **)malloc(sizeof(t_point *) * data->row);
	while (i < data->row)
		data->mtrx[i++] = (t_point *)ft_memalloc(sizeof(t_point) * data->column);
	dprintf(3, "player = %d, row = %d, column = %d\n", data->player, data->row, data->column);
}

void	get_pc(char *str, t_data *data, int fd)
{
	int		i;
	char	*line;

	i = 0;
	data->x_pc = ft_atoi(str);
	data->y_pc = ft_atoi(str + ft_digitnum(data->x_pc));
	data->pc = (char **)malloc(sizeof(char *) * data->x_pc);
	while (i < data->x_pc)
	{
		get_next_line(fd, &line);
		data->pc[i] = (char *)malloc(sizeof(char) * data->y_pc);
		data->pc[i] = ft_strncpy(data->pc[i], line, data->y_pc);
		i++;
		free(line);
	}
	dprintf(3, "pc_x = %d, pc_y = %d\n", data->x_pc, data->y_pc);
}
