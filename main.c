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

void	clear_list(t_coords **list)
{
	while (*list)
	{
		free(*list);
		*list = (*list)->next;
	}
	*list = NULL;
}

void	find_min_distance(t_data *data, int dotrow, int dotcol)
{
	int i;
	int	j;
	int	dist;

	i = -1;
	while (++i < data->row)
	{
		j = -1;
		while (++j < data->column)
		{
			dist = ABS(i - dotrow) + ABS(j - dotcol);
			data->mtrx[i][j].length = dist;
			//dprintf(3, "dist = %d    ", dist);
			// if (data->mtrx[i][j].isEnemy && dist < data->mtrx[dotrow][dotcol].length)
			// {
			// 	data->mtrx[dotrow][dotcol].length = dist;
			// 	// dprintf(3, "!dotrow = %d, dotcol = %d!\n!i = %d, j = %d dist = %d!\n", dotrow, dotcol, i, j, dist);
			// }
		}
	}
}

void	set_distance(t_data *data)
{
	int i;
	int j;
	int flag;

	i = -1;
	flag = 0;
	while (++i < data->row)
	{
		j = -1;
		while (++j < data->column)
			if (data->mtrx[i][j].isEnemy && flag == 0)
			{
				find_min_distance(data, i, j);
				flag = 1;
			}
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

// int		up(t_data *data, int row, int col)
// {
// 	int i;
// 	int j;
// 	int starAmount;

// 	i = -1;
// 	starAmount = 0;
// 	while (++i < data->x_pc)
// 	{
// 		j = -1;
// 		while (++j < data->y_pc)
// 		{
// 			if (data->pc[i][j] == '*' &&s starAmount <= 1)
// 			{
// 				if (data->data->mtrx[row][col].isPlayer)
// 					starAmount++;
// 				if (!data->mtrx[row][col].isPlayer && !data->mtrx[row][col].isEnemy)
// 					res += data->mtrx[row][col];
// 				col++;
// 			}
// 			else if (starAmount > 1)
// 				return (0);
// 			j++;
// 		}
// 		row++;
// 	}
// 	return (res);
// }

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
	// define_coords(data);
	// print_mtrx(data);
	// if (data->my_pos[0] < data->en_pos[0])
	// put_down(data);

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
