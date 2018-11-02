#include <stdio.h>
#include "filler.h"

// void	clear_mtrx(t_data *data, int *counter)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < data->row)
// 	{
// 		j = 0;
// 		while (j < data->column)
// 			data->mtrx[i][j++] = '.';
// 		i++;
// 	}
// 	data->my_pos[0] = 0;
// 	data->my_pos[1] = 0;
// 	*counter = 0;
// }

// void	search_position(t_data *data)
// {
// 	int i;
// 	int j;
// 	int first;
// 	int tbp[2]; // the best position to put the pc; (x, y) coordinates

// 	first = 1;
// 	i = data->my_pos[2];
// 	tbp[0] = data->my_pos[2];
// 	tbp[1] = data->my_pos[3];
// 	dprintf(3, "first data->mtrx[tbp[0]][tbp[1]] = %d\n", data->mtrx[tbp[0]][tbp[1]]);
// 	while (i < data->row)
// 	{
// 		j = -1;
// 		while (++j < data->column)
// 		{
// 			if (data->mtrx[i][j] == data->player && data->mtrx[i + 1][j] != data->player)
// 				if (data->mtrx[i + 1][j] - 48 < data->mtrx[i][j])
// 				{
// 					tbp[0] = i;
// 					tbp[1] = j;
// 				}
// 			if (data->mtrx[i][j] == data->player && data->mtrx[i][j + 1] != data->player)
// 				if (data->mtrx[i][j + 1] - 48 < data->mtrx[i + 1][j])
// 				{
// 					tbp[0] = i;
// 					tbp[1] = j;
// 				}
// 			if (data->mtrx[i][j] == data->player && data->mtrx[i][j - 1] != data->player)
// 				if (data->mtrx[i][j - 1] - 48 < data->mtrx[i][j + 1])
// 				{
// 					tbp[0] = i;
// 					tbp[1] = j;
// 				}
// 		}
// 		i++;
// 	}
// 	dprintf(3, "changed tbp[0] = %d, tbp[1] = %d\n", tbp[0], tbp[1]);
// 	if (tbp[0] == data->my_pos[2] && tbp[1] == data->my_pos[3])
// 	{
// 		tbp[0] = data->my_pos[0];
// 		tbp[1] = data->my_pos[1];
// 	}
// 	data->my_pos[0] = tbp[0];
// 	data->my_pos[1] = tbp[1];
// 	// define_coords(data);
// }

// void	init(t_check *tmp, int x, int y)
// {
// 	tmp->i = x - 1;
// 	tmp->j = y;
// 	tmp->i_pc = 0;
// 	tmp->j_pc = 0;
// 	tmp->check = 0;
// }

// int		change_coords(t_data *data, char enemy)
// {
// 	int match;
// 	t_check *tmp;

// 	tmp = (t_check *)malloc(sizeof(t_check));
// 	init(tmp, data->X, data->Y);
// 	match = 0;
// 	dprintf(3, "i = %d, j = %d\n", tmp->i, tmp->j);
// 	while (tmp->i_pc < data->x_pc)
// 	{
// 		tmp->i++;
// 		tmp->j_pc = 0;
// 		tmp->j = data->Y;
// 		while (tmp->j_pc < data->y_pc)
// 		{
// 			if (match == 0 && data->pc[tmp->i_pc][tmp->j_pc] == '*' &&
// 				data->mtrx[tmp->i][tmp->j] == data->player)
// 			{
// 				dprintf(3, "match = 1\n");
// 				match = 1;
// 				// tmp->j_pc++;
// 			}
// 			else if (match == 1 && data->pc[tmp->i_pc][tmp->j_pc] == '*' &&
// 				(data->mtrx[tmp->i][tmp->j] == data->player || data->mtrx[tmp->i][tmp->j] == enemy))
// 			{
// 				dprintf(3, "match = -1\n");
// 				match = -1;
// 				return (0);
// 			}
// 			tmp->j_pc++;
// 			tmp->j++;
// 		}
// 		tmp->i_pc++;
// 	}
// 	if (match == 0)
// 		return (0);
// 	return (1);
// }

// int		down(t_data *data, char enemy)
// {
// 	int i;
// 	int j;

// 	i = -1;
// 	enemy = 'x';
// 	while (++i < data->x_pc)
// 	{
// 		j = -1;
// 		while (++j < data->y_pc && data->pc[i][j] == '.')
// 			data->Y--;
// 		if (data->pc[i][j] == '*' && i != data->x_pc - 1)
// 		{
// 			if (data->x_pc != 1 && j == 0 && data->pc[i + 1][j] == '*'
// 				&& data->mtrx[data->X + 1][data->Y] == data->player)
// 			{
// 				i++;
// 				data->X++;
// 			}
// 			break ;
// 		}
// 		if (j == data->y_pc - 1)
// 		{
// 			data->X--;
// 			data->Y += j;
// 		}
// 	}
// 	dprintf(3, "after down data->X = %d, data->Y = %d\n", data->X, data->Y);
// 	if (change_coords(data, enemy))
// 	// if (data->mtrx[data->X + data->x_pc - 1][data->Y + data->y_pc - 1] != data->player
// 	// 	&& data->mtrx[data->X + data->x_pc - 1][data->Y + data->y_pc - 1] != enemy &&
// 	// 	data->mtrx[data->X + data->x_pc - 1][data->Y] != data->player && data->mtrx[data->X + data->x_pc - 1][data->Y] != enemy)
// 		return (1);
// 	return (0);
// }

// int		up(t_data *data, char enemy)
// {
// 	data->X = data->my_pos[0] - data->x_pc + 1;
// 	data->Y = data->my_pos[1];
// 	if (data->mtrx[data->X][data->Y] == data->player &&
// 		data->mtrx[data->X][data->Y + data->y_pc - 1] != data->player
// 		&& data->mtrx[data->X][data->Y + data->y_pc - 1] != enemy)
// 		return (1);
// 	else
// 	{
// 		data->Y = 0;
// 		while (data->mtrx[data->X][data->Y] != data->player && data->Y)
// 		{
// 			if (change_coords(data, enemy))
// 				return (1);
// 			data->Y++;
// 			if (data->Y == data->column)
// 			{
// 				dprintf(3, "nulling\n");
// 				data->Y = 0;
// 				data->X--;
// 			}
// 		}
// 	}
// 	dprintf(3, "after up data->X = %d, data->Y = %d\n", data->X, data->Y);
// 	data->mtrx[data->X][data->Y - 1] = 255;
// 	return (0);
// }

// void	define_coords(t_data *data)
// {
// 	char enemy;

// 	enemy = data->player == 'o' ? 'x' : 'o';
// 	data->X = data->my_pos[0];
// 	data->Y = data->my_pos[1];
// 	if (data->X + data->x_pc - 1 >= data->row || data->Y + data->y_pc - 1 >= data->column)
// 	{
// 		data->X = data->my_pos[2];
// 		data->Y = data->my_pos[3];
// 	}
// 	dprintf(3, "data->X = %d, data->Y = %d\n", data->X, data->Y);
// 	if (!down(data, enemy))
// 	{
// 		if (!up(data, enemy))
// 		{
			
// 			data->X = data->my_pos[0];
// 			data->Y = data->my_pos[1];
// 			data->mtrx[data->X][data->Y + 1] = 255;
// 			search_position(data);
// 			return (define_coords(data));
// 		}
// 	}
// 	dprintf(3, "data->X = %d, data->Y = %d\n", data->X, data->Y);
// }

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

// void	find_enemy(t_data *data)
// {
// 	int i;
// 	int j;
// 	int check;

// 	i = -1;
// 	check = 0;
// 	while (++i < data->row)
// 	{
// 		j = -1;
// 		while (++j < data->column)
// 		{
// 			if ((data->mtrx[i][j].isEnemy == 1) ||
// 			{
// 				data->en_pos[0] = i;
// 				data->en_pos[1] = j;
// 				// data->mtrx[i][j] = 0;
// 				return  ;
// 			}
// 		}
// 	}
// }

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

void	enemy_min_dist(t_data *data, int starrow, int starcol, int player[2])
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->row)
	{
		j = -1;
		while (++j < data->column)
		{
			if (data->mlx[i][j].isEnemy)
		}
	}
}

void	star_minimal_distance(t_data *data, int starrow, int starcol)
{
	int	iter[2];

	iter[0] = -1;
	while (++iter[0] < data->row)
	{
		iter[1] = -1;
		while (++iter[1] < data->column)
		{
			if (data->mlx[iter[0]][iter[1]].isPlayer)
				enemy_min_dist(data, i, j, iter);
		}
	}
}

void	search_position(t_data *data)
{
	int i;
	int j;

	i = -1;
	data->min = 255;
	while (++i < data->x_pc)
	{
		j = -1;
		while (++j < data->y_pc)
		{
			if (data->pc[i][j] == '*')
				star_minimal_distance(data, i, j);
		}
	}
}

void	get_data(char *line, t_data *data, int fd)
{
	char	*str1;
	char	*str2;

	get_pc(line + 6, data, fd);
	set_distance(data);
	search_position(data);
	// define_coords(data);
	dprintf(3, "\nDistance\n");
	print_mtrx(data);
	// if (data->my_pos[0] < data->en_pos[0])
	// put_down(data);

	data->X = 0;
	data->Y = 0;
	str1 = ft_itoa(data->X);
	str2 = ft_itoa(data->Y);
	dprintf(3, "%d %d\n", data->X, data->Y);
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
	tmp = 0;
	while (get_next_line(0, &line) && tmp == 0)
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
			// clear_mtrx(data, &i);
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