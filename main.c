#include "filler.h"

void	print_mtrx(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			if (data->mtrx[i][j].isEnemy)
				dprintf(3, "%3dEn", data->mtrx[i][j].length);
			else if (data->mtrx[i][j].isPlayer)
				dprintf(3, "%3dPl", data->mtrx[i][j].length);
			else
				dprintf(3, "%3d  ", data->mtrx[i][j].length);
			++j;
		}
		dprintf(3, "\n");
		++i;
	}
}

void	clear_mtrx(t_data *data, int *counter)
{
	int i;
	int j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			data->mtrx[i][j].length = 0;
			++j;
		}
		++i;
	}
	*counter = 0;
}

void	find_min_distance(t_data *data, int dotrow, int dotcol)
{
	int i;
	int j;
	int dist;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			dist = ABS(dotrow - i) + ABS(dotcol - j);
			if (data->mtrx[i][j].isEnemy && dist < data->mtrx[dotrow][dotcol].length)
				data->mtrx[dotrow][dotcol].length = dist;
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
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			find_min_distance(data, i, j);
			++j;
		}
		++i;
	}
}

void	ft_arrdel(char **arr, int row)
{
	int i;

	i = 0;
	while (i < row)
		free(arr[i++]);
}

void	print_piece(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->x_pc)
	{
		j = 0;
		while (j < data->y_pc)
		{
			dprintf(3, "%c", data->pc[i][j]);
			j++;
		}
		i++;
		dprintf(3, "\n");
	}
}

void	get_data(char *line, t_data *data, int fd)
{
	char	*str1;
	char	*str2;
	t_coords *list;

	list = NULL;
	get_pc(line + 6, data, fd);
	print_mtrx(data);
	dprintf(3, "----distances are not set---- line = %s\n", line);
	set_distance(data);
	dprintf(3, "----distances were set----\n");
	print_mtrx(data);
	search_position(data, list);
	ft_arrdel(data->pc, data->x_pc);
	// if (!list)
	// {
	// 	data->coords->x = 0;
    // 	data->coords->y = 0;
	// }
	clear_list(&list);
	str1 = ft_itoa(data->coords->x);
	str2 = ft_itoa(data->coords->y);
	// dprintf(3, )
	dprintf(3, "%d %d\n", data->coords->x, data->coords->y);
	str1 = ft_strcat(str1, " ");
	str2 = ft_strcat(str2, "\n");
	ft_putstr(ft_strcat(str1, str2));
	// return(ft_strcat(str1, str2));
}

int main(void)
{
	int			i;
	int			fd;
	char		*line;
	char		*ptr;
	t_data		*data;

	data = (t_data *)ft_memalloc(sizeof(t_data));
	fd = open("log", O_RDWR | O_CREAT | O_TRUNC);
	i = -1;
	while (get_next_line(0, &line))
	{
		if ((ptr = ft_strstr(line, "[./omaslova.filler]")))
		{
			data->player = *(ptr - 4) == '1' ? 'o' + 100 : 'x' + 100;
			data->enemy = data->player == 'o' + 100 ? 'x' + 100 : 'o' + 100;
		}
		else if ((ptr = ft_strstr(line, "Plateau")) && i == -1)
		{
			set_data(line, data);
			++i;
		}
		else if (ft_strstr(line, "0123456789"))
		{
			free(line);
			continue ;
		}
		else if (i < data->row && !(ft_strstr(line, "Plateau")))
			i = set_mtrx(line + 4, data, i);
		else if ((ptr = ft_strstr(line, "Piece")))
		{
			get_data(ptr, data, 0);
			clear_mtrx(data, &i);
		}
		free(line);
	}
	close(fd);
	// printf("%s", get_data(data));
	// ft_arrdel(data->pc, data->x_pc);
	// ft_arrdel(data->mtrx, data->row);
	// ft_memdel((void**)data->mtrx);
	// free(data);
	// free(data->mtrx);
	// system ("leaks a.out");
	return (0);
}
