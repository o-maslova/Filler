#include <stdio.h>
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
			dist = ABS(dotrow - i) + ABS(dotcol - j);
			//dprintf(3, "dist = %d    ", dist);
			if (data->mtrx[i][j].isEnemy && dist < data->mtrx[dotrow][dotcol].length)
			{
				data->mtrx[dotrow][dotcol].length = dist;
				// dprintf(3, "!dotrow = %d, dotcol = %d!\n!i = %d, j = %d dist = %d!\n", dotrow, dotcol, i, j, dist);
			}
		}
	}
}

void	set_distance(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->row)
	{
		j = -1;
		while (++j < data->column)
			find_min_distance(data, i, j);
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

// void	enemy_min_dist(t_data *data, int starrow, int starcol, int player[2])
// {
// 	int		i;
// 	int		j;

// 	i = -1;
// 	while (++i < data->row)
// 	{
// 		j = -1;
// 		while (++j < data->column)
// 		{
// 			if (data->mlx[i][j].isEnemy)
// 		}
// 	}
// }

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
// 			if (data->pc[i][j] == '*' && starAmount <= 1)
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

int		down(t_data *data, int row, int col)
{
	int i;
	int j;
	int res;
	int starAmount;

	i = -1;
	res = 0;
	starAmount = 0;
	while (++i < data->x_pc)
	{
		j = -1;
		while (++j < data->y_pc)
		{
			if (data->pc[i][j] == '*' && starAmount <= 1)
			{
				if (data->mtrx[row][col].isPlayer)
					starAmount++;
				if (!data->mtrx[row][col].isEnemy)
					res += data->mtrx[row][col].length;
				col++;
			}
			else if (starAmount > 1)
			{
				dprintf(3, "there starAmount = %d\n", starAmount);
				return (0);
			}
			j++;
		}
		row++;
	}
	dprintf(3, "res = %d, starAmount = %d\n", res, starAmount);
	return (res);
}

int		star_minimal_distance(t_data *data, int row, int col, t_coords *coords)
{
	int i;
	int j;
	int res;
	int tmp;

	i = -1;
	res = 255;
	while (++i < data->x_pc)
	{
		j = -1;
		while (++j < data->y_pc)
		{
			if (data->pc[i][j] == '*')
			{
				if ((tmp = down(data, row, col)) < res)
				{
					coords->x = row + i;
					coords->y = col - j;
					res = tmp;
				}
				// if ((tmp = down(data, row - data->x_pc - 1, col)) < res)
				// {
				// 	coords->x = row - i;
				// 	coords->y = col - j;
				// 	res = tmp;
				// }
			}
		}
	}
	dprintf(3, "row = %d, column = %d\n", row, col);
	dprintf(3, "res = %d, x = %d, y = %d\n", res, coords->x, coords->y);
	return (res);
}

void	search_position(t_data *data)
{
	int i;
	int j;
	int min;
	int tmp;
	t_coords *tmp_coords;

	i = -1;
	min = 255;
	data->coords = (t_coords *)malloc(sizeof(t_coords));
	tmp_coords = (t_coords *)malloc(sizeof(t_coords));
	while (++i < data->row)
	{
		j = -1;
		while (++j < data->column)
		{
			if (data->mtrx[i][j].isPlayer)
			{
				if ((tmp = star_minimal_distance(data, i, j, tmp_coords)) < min)
				{
					min = tmp;
					data->coords = tmp_coords;
				}
				if (min == 0)
				{
					data->coords->x = 0;
					data->coords->y = 0;
				}
			}
		}
	}
}

void	get_data(char *line, t_data *data, int fd)
{
	char	*str1;
	char	*str2;
	int		x;
	int		y;

	get_pc(line + 6, data, fd);
	set_distance(data);
	search_position(data);
	x = data->coords->x;
	y = data->coords->y;
	// define_coords(data);
	dprintf(3, "\nDistance\n");
	print_mtrx(data);
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
	int			tmp;
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