#include <stdio.h>
#include "filler.h"

// void	put_up(t_data *data)
// {

// }

void	put_down(t_data *data)
{
	int i;
	int j;
	int i_piece;
	int j_piece;

	i_piece = -1;
	i = data->my_pos[0];
	while (++i_piece < data->x_piece)
	{
		j_piece = 0;
		j = data->my_pos[1];
		while (data->piece[i_piece][j_piece] == '.')
			j_piece++;
		if (data->piece[0][0] == '.' && data->piece[1][0] != '.')
			j--;
		while (j_piece < data->y_piece)
		{
			data->piece[i_piece][j_piece] = data->player;
			data->matrix[i][j++] = data->piece[i_piece][j_piece++];
		}
		i++;
	}
	// data->my_pos[0] = i - 2;
	// data->my_pos[1] = j - 2;
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
	printf("enemy : %d, %d\n", data->en_pos[0], data->en_pos[1]);
	printf("my : %d, %d\n", data->my_pos[0], data->my_pos[1]);
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
			printf("%c", data->matrix[i][j++]);
		printf("\n");
		i++;
	}
}

void	set_matrix(char *line, t_data *data)
{
	static int	i;
	int			j;

	line += 4;
	j = 0;
	if (i == 0)
		data->matrix = (char **)malloc(sizeof(char *) * data->row);
	data->matrix[i] = (char *)malloc(sizeof(char) * data->column);
	while (j < data->column && *line != '\n')
	{
		if ((data->player == 'o' && (*line == 'o' || *line == 'O')) ||
		(data->player == 'x' && (*line == 'x' || *line == 'X')))
		{
			data->my_pos[0] = i;
			data->my_pos[1] = j;
		}
		else if ((data->player == 'o' && *line != 'o' && *line != 'O') ||
		(data->player == 'x' && *line != 'x' && *line != 'X'))
		{
			data->en_pos[0] = i;
			data->en_pos[1] = j;
		}
		data->matrix[i][j++] = *line++;
	}
	i++;
}

void	set_data(char *line, t_data *data)
{
	int i;

	i = 0;
	line += 8;
	data->row = ft_atoi(line);
	line += ft_digitnum(data->row);
	data->column = ft_atoi(line);
	printf("player = %c, row = %d, column = %d\n", data->player, data->row, data->column);
}

void	get_piece(char *str, t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	data->x_piece = ft_atoi(str);
	data->y_piece = ft_atoi(str + ft_digitnum(data->x_piece));
	data->piece = (char **)malloc(sizeof(char *) * data->x_piece);
	while (get_next_line(0, &line) && ft_strchr(line, '*'))
	{
		data->piece[i] = (char *)malloc(sizeof(char) * data->y_piece);
		data->piece[i] = ft_strncpy(data->piece[i], line, data->y_piece);
		i++;
		free(line);
	}
	printf("piece_x = %d, piece_y = %d\n", data->x_piece, data->y_piece);
}

char	*get_data(char *line, t_data *data)
{
	char	*str1;
	char	*str2;

	printf("%s\n", "go here");
	get_piece(line + 6, data);
	// print_matrix(data);
	// if (data->my_pos[0] < data->en_pos[0])
	// 	put_down(data);
	str1 = ft_itoa(data->my_pos[1]);
	str2 = ft_itoa(data->my_pos[0]);
	str1 = ft_strcat(str1, " ");
	str2 = ft_strcat(str2, "\n");
	return(ft_strcat(str1, str2));
}

int main(void)
{
	int		fd;
	char	*line;
	char	*ptr;
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	fd = open("test", O_RDWR | O_TRUNC | O_CREAT);
	// printf("%d\n", fd);
	while (get_next_line(0, &line))
	{
		dprintf(fd, "%s\n", line);
		free(line);
	}
	close(fd);
	fd = open("test", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if ((ptr = ft_strstr(line, "exec")))
			data->player = *(ptr + 6) == '1' ? 'o' : 'x';
		else if ((ptr = ft_strstr(line, "Plateau")))
			set_data(line, data);
		else if ((ptr = ft_strchr(line, '0')))
			set_matrix(line, data);
		else if ((ptr = ft_strstr(line, "Piece")))
			printf("%s", get_data(ptr, data));
		free(line);
	}
	// close(fd);
	// printf("%s", get_data(data));
	// ft_arrdel(data->piece, data->x_piece);
	// ft_arrdel(data->matrix, data->row);
	// ft_memdel((void**)data->matrix);
	// free(data);
	// free(data->matrix);
	// system ("leaks a.out");
	return (0);
}