#include "view.h"

void	init(t_win *win)
{
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, HEIGTH, WIDTH, "Filler");
}

int		allocate_mem(t_win *win, char *line, int i)
{
	line += 8;
	VIEW_ROW = ft_atoi(line);
	line += ft_digitnum(VIEW_ROW);
	VIEW_COLUMN = ft_atoi(line);
	win->matrix = (char **)ft_memalloc(sizeof(char *) * VIEW_ROW);
	while (++i < VIEW_ROW)
		win->matrix[i] = (char *)ft_memalloc(sizeof(char) * VIEW_COLUMN);
	return (0);
}

void		set_matrix(t_win *win)
{
	int i;
	int j;
	int k;
	char *tmp;

	i = 0;
	while (i < VIEW_ROW)
	{
		j = -1;
		k = 4;
		get_next_line(g_fd_m, &tmp);
		while (++j < VIEW_COLUMN)
		{
			tmp[k] = ft_tolower(tmp[k]);
			win->matrix[i][j] = tmp[k];
			++k;
		}
		free(tmp);
		++i;
	}
}

void	search_data(char **line)
{
	int i;

	i = 1;
	while (!(ft_strstr(*line, "0123456789")) && i > 0)
	{
		free(line);
		i = get_next_line(g_fd_m, line);
	}
}

int			game(t_win *win)
{
	char *line;

	while (get_next_line(g_fd_m, &line) > 0)
	{
		if (ft_strstr(line, "0123456789"))
		{
			draw_players(win);
			mlx_clear_window(win->mlx_ptr, win->win_ptr);
			set_matrix(win);
			draw_field(win);
			draw_matrix(win);
		}
		else if (ft_strstr(line, "fin"))
			display_winner(win, line);
		// free(line);
	}
	return (0);
}

static int	exit_x(void)
{
	exit(0);
}

static int	key_hook(int keycode, t_win *win)
{
	if (keycode == 53)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		exit(0);
	}
	else if (keycode == 49)
		mlx_loop_hook(win->mlx_ptr, game, win);
	return (0);
}

void	define_values(t_win *win)
{
	int		i;
	char	*line;
	char	*ptr;

	i = -1;
	while (get_next_line(g_fd_m, &line))
	{
		if ((ptr = ft_strstr(line, "[./omaslova.filler]")))
		{
			g_player = *(ptr - 4) == '1' ? 'o' : 'x';
			g_enemy = g_player == 'o' ? 'x' : 'o';
		}
		if (ft_strstr(line, "Plateau") && i == -1)
			i = allocate_mem(win, line, i);
		if (ft_strstr(line, "0123456789"))
			set_matrix(win);
		free(line);
	}
}

int		main(void)
{
	int		i;
	char	*line;
	t_win	*win;

	i = -1;
	g_fd_m = open("viuviu", O_RDONLY);
	g_fd = open("log", O_RDWR | O_CREAT | O_TRUNC);
	win = (t_win *)ft_memalloc(sizeof(t_win));
	init(win);
	define_values(win);
	search_data(&line);
	draw_field(win);
	draw_matrix(win);
			// mlx_hook(win->win_ptr, 2, 0, deal_key, win);
			// mlx_loop(win->mlx_ptr);
	draw_players(win);
	mlx_hook(win->win_ptr, 2, 0, key_hook, win->mlx_ptr);
	mlx_hook(win->win_ptr, 17, 1L << 17, exit_x, 0);
	mlx_loop(win->mlx_ptr);
	ft_arrdel(win->matrix, VIEW_ROW);
	free(win);
	return (0);
}