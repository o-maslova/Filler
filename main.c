#include <stdio.h>
#include "filler.h"

// void	put_up(t_data *data)
// {

// }

// void	algorithm(t_data *data)
// {

// }

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

int		another_side(t_data *data)
{
	int i;
	int j;
	int i_piece;
	int change;

	i = -1;
	change = 0;
	i_piece = 0;
	data->y_piece -= 1;
	dprintf(3, "THERE_2\n");
	while (++i < data->row)
	{
		j = -1;
		while (++j < data->column)
		{
			// dprintf(3, "data->matrix[i][j] = %c, j = %d    ", );
			if (data->matrix[i][j] != data->player && data->matrix[i][j + 1] == data->player
				&& j + 1 >= data->y_piece)
			{
				dprintf(3, "THERE_3\n");
				data->X = i;
				data->Y = j + 1;
				while (data->piece[i_piece][data->y_piece--] == '*')
					data->Y--;
				change = 1;
			}
			// dprintf(3, "\n");
		}
	}
	if (change == 0)
		return (0);
	return (1);
}

int		change_coords(t_data *data)
{
	int i;
	int j;
	int change;
	char enemy;

	i = -1;
	change = 0;
	enemy = data->player == 'o' ? 'x' : 'o';
	while (++i < data->row)
	{
		j = -1;
		while (++j < data->column)
			if (data->matrix[i][j] == data->player &&
				data->matrix[i][j + 1] != data->player)
			{
				if (data->matrix[i + 1][j] != data->player && data->matrix[i + 1][j] != enemy)
				{
					data->X = i;
					data->Y = j;
					change = 1;
				}
			}
			// else if (data->matrix[i][j] == data->player &&
			// 	data->matrix[i][j + 1] != data->player)
	}
	if (change == 0)
		if (!another_side(data))
			return (0);
	return (1);
}

void	define_coords(t_data *data)
{
	int i;
	int j;
	int i_piece;
	int j_piece;

	i_piece = -1;
	if (data->matrix[data->my_pos[2]][data->my_pos[3] + 1] != '0' &&
		data->matrix[data->my_pos[2]][data->my_pos[3] + 1] < data->matrix[data->my_pos[0]][data->my_pos[1] + 1])
	{
		i = data->my_pos[2];
		j = data->my_pos[3];
	}
	else
	{
		i = data->my_pos[0];
		j = data->my_pos[1];
	}
	// while (1)
	// {
	while (++i_piece < data->x_piece)
	{
		j_piece = 0;
		while (data->piece[i_piece][j_piece] == '.' && j_piece < data->y_piece)
			j_piece++;
		if (j_piece < data->y_piece)
			break ;
	}
	data->X = i - i_piece;
	data->Y = j - j_piece;
	if (data->matrix[data->X][data->Y + 1] != '0')
	{
		dprintf(3, "THERE\n");
		if (!change_coords(data))
		{
			data->X = 0;
			data->Y = 0;
		}
	}
}

void	set_distance(t_data *data)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			if (data->matrix[i][j] == '.')
			{
				tmp = ABS(i - data->en_pos[0]);
				tmp += ABS(j - data->en_pos[1]);
				tmp = tmp > 9 ? 0 : tmp;
				data->matrix[i][j] = *ft_itoa(tmp);
			}
			j++;
		}
		i++;
	}
}

void	find_enemy(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->row)
	{
		j = -1;
		while (++j < data->column)
		{
			if ((data->player == 'o' && data->matrix[i][j] == 'x') ||
			(data->player == 'x' && data->matrix[i][j] == 'o'))
			{
				data->en_pos[0] = i;
				data->en_pos[1] = j;
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
			dprintf(3, "%c", data->matrix[i][j++]);
		dprintf(3, "\n");
		i++;
	}
}

int		set_matrix(char *line, t_data *data, int i)
{
	int j;
	int check;
	
	j = 0;
	check = 0;
	while (j < data->column)
	{
		if (*line != '.')
			*line = ft_tolower(*line);
		if (check == 0 && ((data->player == 'o' && *line == 'o') ||
		(data->player == 'x' && *line == 'x')))
		{
			check = 1;
			data->my_pos[2] = i;
			data->my_pos[3] = j;
			dprintf(3, "data->my_pos[0] = %d, data->my_pos[1] = %d\n", data->my_pos[0], data->my_pos[1]);
		}
		if ((data->player == 'o' && *line == 'o') ||
		(data->player == 'x' && *line == 'x'))
		{
			data->my_pos[0] = i;
			data->my_pos[1] = j;
		}
		data->matrix[i][j++] = *line++;
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
	data->matrix = (char **)malloc(sizeof(char *) * data->row);
	while (i < data->column)
		data->matrix[i++] = (char *)malloc(sizeof(char) * data->column);
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
	print_matrix(data);
	define_coords(data);
	// if (data->my_pos[0] < data->en_pos[0])
	// 	put_down(data);
	
	str1 = ft_itoa(data->X);
	str2 = ft_itoa(data->Y);
	dprintf(3, "%d %d\n", data->X, data->Y);
	// printf("%d %d\n", data->my_pos[0], data->my_pos[1]);
	// ft_putnbr(data->my_pos[1]);
	// ft_putchar(' ');
	// ft_putnbr(data->my_pos[0]);
	// ft_putchar('\n');
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
	// fd = open("test", O_RDWR | O_TRUNC | O_CREAT);
	// printf("%d\n", fd);
	// while (get_next_line(0, &line))
	// {
	// 	dprintf(fd, "%s\n", line);
	// 	free(line);
	// }
	// close(fd);
	// fd = open("test", O_RDONLY);
	fd = open("log", O_RDWR | O_CREAT);
	i = 0;
	while (get_next_line(0, &line))
	{
		if ((ptr = ft_strstr(line, "[./a.out]")))
		{	
			// dprintf(3, "ptr = %sn", ptr - 4);
			data->player = *(ptr - 4) == '1' ? 'o' : 'x';
		}
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