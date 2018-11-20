#include "filler.h"

int		set_mtrx(char *line, t_data *data, int i)
{
	int j;
	
	j = 0;
	//dprintf(3, "i = %d", i);
	while (j < data->column)
	{
		dprintf(3, "%c", line[j]);
		line[j] = ft_tolower(line[j]);
		data->mtrx[i][j].length = 255; //(unsigned char)line[j]++;
		// dprintf(3, "%c", line[j]);
		if (line[j] + 100 == data->player)
			data->mtrx[i][j].isPlayer = 1;
		if (line[j] + 100 == data->enemy)
			data->mtrx[i][j].isEnemy = 1;
		++j;
	}
	dprintf(3, "\n");
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
	data->mtrx = (t_point **)ft_memalloc(sizeof(t_point *) * data->row);
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
	data->pc = (char **)ft_memalloc(sizeof(char *) * data->x_pc);
	while (i < data->x_pc)
	{
		get_next_line(fd, &line);
		data->pc[i] = (char *)ft_memalloc(sizeof(char) * data->y_pc);
		data->pc[i] = ft_strncpy(data->pc[i], line, data->y_pc);
		i++;
		free(line);
	}
	dprintf(3, "pc_x = %d, pc_y = %d\n", data->x_pc, data->y_pc);
}