#include "filler.h"

void	clear_mtrx(t_data *data, int *counter)
{
	int i;
	int j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
			data->mtrx[i][j++].length = 0;
		i++;
	}
	*counter = 0;
}

void	set_distance(t_data *data)
{
	int i[2];
	int j[2];
	int dist;

	i[0] = -1;
	while (++i[0] < data->row)
	{
		j[0] = -1;
		while (++j[0] < data->column)
		{
			i[1] = -1;
			while (++i[1] < data->row)
			{
				j[1] = -1;
				while (++j[1] < data->column)
				{
					dist = ABS(i[0] - i[1]) + ABS(j[0] - j[1]);
					if (data->mtrx[i[1]][j[1]].isEnemy && dist < data->mtrx[i[0]][j[0]].length)
						data->mtrx[i[0]][j[0]].length = dist;
				}
			}
		}
			// find_min_distance(data, i, j);
	}
}

void	ft_arrdel(char **arr, int row)
{
	int i;

	i = 0;
	while (i < row)
		free(arr[i++]);
}

void	print_mtrx(t_data *data)
{
	int i;
	int j;

	i = 0;
	// dprintf(3, "enemy : %d, %d\n", data->en_pos[0], data->en_pos[1]);
	// dprintf(3, "my : %d, %d\n", data->my_pos[0], data->my_pos[1]);
	while (i < data->row)
	{
		j = -1;
		while (++j < data->column)
		{
			if (data->mtrx[i][j].isEnemy)
				dprintf(3, "%3dEn", data->mtrx[i][j].length);
			else if (data->mtrx[i][j].isPlayer)
				dprintf(3, "%3dPl", data->mtrx[i][j].length);
			else
				dprintf(3, "%3d  ", data->mtrx[i][j].length);
		}
		dprintf(3, "\n");
		i++;
	}
}

void	get_data(char *line, t_data *data, int fd)
{
	char	*str1;
	char	*str2;
	int		x;
	int		y;
	t_coords *list;

	list = NULL;
	get_pc(line + 6, data, fd);
	set_distance(data);
	print_mtrx(data);
	search_position(data, list);
	clear_list(&list);
	x = data->coords->x;
	y = data->coords->y;

	str1 = ft_itoa(x);
	str2 = ft_itoa(y);
	dprintf(3, "%d %d\n", x, y);
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

	data = (t_data *)malloc(sizeof(t_data));
	fd = open("log", O_RDWR | O_CREAT | O_TRUNC);
	i = 0;
	while (get_next_line(0, &line))
	{
		if ((ptr = ft_strstr(line, "[./a.out]")))
		{
			data->player = *(ptr - 4) == '1' ? 'o' + 100 : 'x' + 100;
			data->enemy = data->player == 'o' + 100 ? 'x' + 100 : 'o' + 100;
		}
		if ((ptr = ft_strstr(line, "Plateau")))
			set_data(line, data);	
		if ((ptr = ft_strstr(line, "Piece")))
		{
			get_data(ptr, data, 0);
			clear_mtrx(data, &i);
		}
		if ((ft_strchr(line, '0') && (ptr = ft_strchr(line, '.'))))
			i = set_mtrx(ptr, data, i);
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
