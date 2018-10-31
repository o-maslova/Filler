#include <stdio.h>
#include "filler.h"

void	clear_matrix(t_data *data, int *counter)
{
	int i;
	int j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
			data->matrix[i][j++] = '.';
		i++;
	}
	data->my_pos[0] = 0;
	data->my_pos[1] = 0;
	*counter = 0;
}

int		change_coords(t_data *data)
{
	int i;
	int j;

	// int change;
	// char enemy;

	i = data->X;
	while (i < data->row)
	{
		j = -1;
		while (++j < data->column)
		{
			if (data->matrix[i + 1][j] == data->player && data->x_piece > 1)
			{
				dprintf(3, "i = %d, j = %d WTF\n", i, j);
				data->X--;
			}
			// if (j < data->y_piece && data->piece[i][j] == '*')
			// 	data->Y--;
		}
		// if (i < data->x_piece && data->piece[i][j] == '*')
		// 	data->X--;
		i++;
	}
	return (1);
}

void	define_coords(t_data *data)
{
	int i;
	int j;
	char enemy;
	int flag;

	i = -1;
	enemy = data->player == 'o' ? 'x' : 'o';
	data->X = data->my_pos[0];
	data->Y = data->my_pos[1];
	dprintf(3, "data->X = %d, data->Y = %d\n", data->X, data->Y);
	while (++i < data->x_piece)
	{
		j = -1;
		flag = 0;
		while (++j < data->y_piece && data->piece[i][j] == '.')
		{
			flag++;
			data->Y--;
		}
		if (data->piece[i][j] == '*')
			break ;
		if (flag == j)
		{
			data->X--;
			data->Y += flag - 1;
		}
	}
	dprintf(3, "data->X = %d, data->Y = %d\n", data->X, data->Y);
	if (data->matrix[data->X + 1][data->Y] == data->player || data->matrix[data->X + 1][data->Y] == enemy)
	{
		data->X -= data->x_piece - 1;
		data->Y += flag - 1;
		// while (data->matrix[data->X + 1][data->Y] != data->player)
		// {
		// 	data->Y--;
		// 	dprintf(3, "THERE-\n");
		// }
		dprintf(3, "THERE+\n");
		dprintf(3, "data->X = %d, data->Y = %d\n", data->X, data->Y);
		while (data->matrix[data->X + data->x_piece - 1][data->Y + data->y_piece - 1] == data->player)
		{
			data->X--;
		}
		// if (data->x_piece > 1)
		// 	data->my_pos[0]--;
		// else
		// 	return ;
		// data->x_piece--;
	}
	// else if (data->matrix[data->X][data->Y + 1] == data->player || data->matrix[data->X][data->Y + 1] == enemy)
	// {
	// 	// i = 0;
	// 	dprintf(3, "THERE_2\n");
	// 	data->my_pos[1]--;
	// 	// j++;
	// 	// if (j == data->y_piece)
	// 	// 	j = 0;
	// }
		// if (!change_coords(data))
		// {
		// 	data->X = 0;
		// 	data->Y = 0;
		// }
	// if (flag == 0)
	// {
	// 	i = 0;
	// 	j = 0;
	// 	return ;
	// }
	// return (define_coords(data));
	// if (data->X + data->x_piece > data->row)
	// {
	// 	dprintf(3, "RECURSION\n");
	// 	data->my_pos[0] = data->my_pos[2];
	// 	data->my_pos[1] = data->my_pos[3];
	// 	return (define_coords(data));
	// }
}

void	search_position(t_data *data)
{
	int i;
	int j;
	int first;
	int tbp[2]; // the best position to put the piece; (x, y) coordinates

	first = 1;
	i = data->my_pos[2];
	tbp[0] = data->my_pos[2];
	tbp[1] = data->my_pos[3];
	dprintf(3, "data->my_pos[0] = %d\n", data->my_pos[0]);
	dprintf(3, "data->my_pos[1] = %d\n", data->my_pos[1]);
	dprintf(3, "data->my_pos[2] = %d\n", data->my_pos[2]);
	dprintf(3, "data->my_pos[3] = %d\n", data->my_pos[3]);
	dprintf(3, "tbp[0] = %d  ", tbp[0]);
	dprintf(3, "tbp[1] = %d\n", tbp[1]);
	dprintf(3, "data->matrix[tbp[0]][tbp[1]] = %c  ", data->matrix[tbp[0]][tbp[1]]);
	dprintf(3, "data->matrix[tbp[0]][tbp[1]] = %d\n", data->matrix[tbp[0]][tbp[1]] - 48);
	while (i < data->row)
	{
		j = -1;
		while (++j < data->column)
		{
			while (data->matrix[i][j] == data->player && data->matrix[i][j + 1] == data->player)
				j++;
			if (data->matrix[i][j] == data->player && data->matrix[i][j + 1] != data->player && !first &&
				data->matrix[i][j + 1] - 48 < data->matrix[tbp[0]][tbp[1] + 1] - 48)
			{
				// dprintf(3, "VIUVIU\n");
				// dprintf(3, "data->matrix[tbp[0]][tbp[1]] = %c  ", data->matrix[tbp[0]][tbp[1]]);
				// dprintf(3, "data->matrix[tbp[0]][tbp[1]] = %d\n", data->matrix[tbp[0]][tbp[1]] - 48);
				// dprintf(3, "i = %d, j = %d\n", i, j);
				tbp[0] = i;
				tbp[1] = j;
			}
			else if (data->matrix[i][j] == data->player && data->matrix[i][j + 1] != data->player && first)
			{
				first = 0;
				tbp[0] = i;
				tbp[1] = j;
			}
		}
		// dprintf(3, "tbp[0] = %d  ", tbp[0]);
		// dprintf(3, "tbp[1] = %d\n", tbp[1]);
		i++;
	}
	if (tbp[0] == data->my_pos[2] && tbp[1] == data->my_pos[3])
	{
		tbp[0] = data->my_pos[0];
		tbp[1] = data->my_pos[1];
	}
	if (tbp[0] + data->x_piece > data->row || tbp[1] + data->y_piece > data->column)
	{
		tbp[0] = data->my_pos[2];
		tbp[1] = data->my_pos[3];
	}
	// if (data->matrix[tbp[0] + 1][tbp[1]] == 111 || data->matrix[tbp[0]][tbp[1] + 1] == 111)
		
	dprintf(3, "tbp[0] = %d\n", tbp[0]);
	dprintf(3, "tbp[1] = %d\n", tbp[1]);
	data->my_pos[0] = tbp[0];
	data->my_pos[1] = tbp[1];
}

void	set_distance(t_data *data)
{
	int i;
	int j;
	int tmp;

	i = -1;
	while (++i < data->row)
	{
		j = -1;
		while (++j < data->column)
		{
			if (data->matrix[i][j] == '.')
			{
				tmp = ABS(i - data->en_pos[0]);
				tmp += ABS(j - data->en_pos[1]);
				tmp = (unsigned char)tmp;
				data->matrix[i][j] = tmp;
			}
		}
	}
}

void	find_enemy(t_data *data)
{
	int i;
	int j;
	int check;

	i = -1;
	check = 0;
	while (++i < data->row)
	{
		j = -1;
		while (++j < data->column)
		{
			if (check == 0 && ((data->player == 'o' && data->matrix[i][j] == 'o') ||
			(data->player == 'x' && data->matrix[i][j] == 'x')))
			{
				check = 1;
				data->my_pos[2] = i;
				data->my_pos[3] = j;
			}
			if ((data->player == 'o' && data->matrix[i][j] == 'x') ||
			(data->player == 'x' && data->matrix[i][j] == 'o'))
			{
				data->en_pos[0] = i;
				data->en_pos[1] = j;
				// data->matrix[i][j] = 0;
				return  ;
			}
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

void	print_matrix(t_data *data)
{
	int i;
	int j;

	i = 0;
	dprintf(3, "enemy : %d, %d\n", data->en_pos[0], data->en_pos[1]);
	dprintf(3, "my : %d, %d\n", data->my_pos[0], data->my_pos[1]);
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
			dprintf(3, "%d  ", data->matrix[i][j++]);
		dprintf(3, "\n");
		i++;
	}
}

int		set_matrix(char *line, t_data *data, int i)
{
	int j;
	
	j = 0;
	while (j < data->column)
	{
		if (*line != '.')
			*line = ft_tolower(*line);
		if ((data->player == 'o' && *line == 'o') ||
			(data->player == 'x' && *line == 'x'))
		{
			data->my_pos[0] = i;
			data->my_pos[1] = j;
			// *line = -1;
		}
		data->matrix[i][j++] = (unsigned char)*line++;
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
	data->matrix = (unsigned char **)malloc(sizeof(unsigned char *) * data->row);
	while (i < data->column)
		data->matrix[i++] = (unsigned char *)malloc(sizeof(unsigned char) * data->column);
	dprintf(3, "player = %c, row = %d, column = %d\n", data->player, data->row, data->column);
}

void	get_piece(char *str, t_data *data, int fd)
{
	int		i;
	char	*line;

	i = 0;
	data->x_piece = ft_atoi(str);
	data->y_piece = ft_atoi(str + ft_digitnum(data->x_piece));
	data->piece = (char **)malloc(sizeof(char *) * data->x_piece);
	while (i < data->x_piece)
	{
		get_next_line(fd, &line);
		data->piece[i] = (char *)malloc(sizeof(char) * data->y_piece);
		data->piece[i] = ft_strncpy(data->piece[i], line, data->y_piece);
		i++;
		free(line);
	}
	dprintf(3, "piece_x = %d, piece_y = %d\n", data->x_piece, data->y_piece);
}

void	get_data(char *line, t_data *data, int fd)
{
	char	*str1;
	char	*str2;

	// printf("%s\n", "go here");
	get_piece(line + 6, data, fd);
	find_enemy(data);
	print_matrix(data);
	set_distance(data);
	search_position(data);
	print_matrix(data);
	define_coords(data);
	// if (data->my_pos[0] < data->en_pos[0])
	// 	put_down(data);
	
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
	int			fd;
	char		*line;
	char		*ptr;
	t_data		*data;

	data = (t_data *)malloc(sizeof(t_data));
	fd = open("log", O_RDWR | O_CREAT);
	i = 0;
	while (get_next_line(0, &line))
	{
		if ((ptr = ft_strstr(line, "[./a.out]")))
			data->player = *(ptr - 4) == '1' ? 'o' : 'x';
		if ((ptr = ft_strstr(line, "Plateau")))
			set_data(line, data);	
		if ((ptr = ft_strstr(line, "Piece")))
		{
			get_data(ptr, data, 0);
			clear_matrix(data, &i);
		}
		if ((ft_strchr(line, '0') && (ptr = ft_strchr(line, '.'))))
		{
			i = set_matrix(ptr, data, i);
		}
		free(line);
	}
	close(fd);
	// printf("%s", get_data(data));
	// ft_arrdel(data->piece, data->x_piece);
	// ft_arrdel(data->matrix, data->row);
	// ft_memdel((void**)data->matrix);
	// free(data);
	// free(data->matrix);
	// system ("leaks a.out");
	return (0);
}