/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <omaslova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:59:32 by omaslova          #+#    #+#             */
/*   Updated: 2018/11/24 13:59:33 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"

int			exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

int			game(t_win *win)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(g_fd_m, &line) > 0)
	{
		if (ft_strstr(line, "0123456789"))
		{
			i = set_matrix(win);
			mlx_clear_window(win->mlx_ptr, win->win_ptr);
			draw_field(win);
			free(line);
			break ;
		}
		else if (ft_strstr(line, "fin"))
		{
			display_winner(win, line);
		}
		free(line);
	}
	return (0);
}

static int	key_hook(int keycode, t_win *win)
{
	if (keycode == 53)
	{
		ft_arrdel(win->matrix, VIEW_ROW);
		free(win);
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		exit(0);
	}
	else if (keycode == 49)
	{
		mlx_loop_hook(win->mlx_ptr, game, win);
	}
	return (0);
}

int			main(void)
{
	int		i;
	t_win	*win;

	i = -1;
	g_fd_m = 0;
	win = (t_win *)ft_memalloc(sizeof(t_win));
	define_values(win);
	dprintf(g_fd, "w = %d, h = %d", WIDTH, HEIGTH);
	init(win);
	draw_players(win);
	draw_field(win);
	mlx_string_put(win->mlx_ptr, win->win_ptr, win->row + PAD,
	VIEW_COLUMN * CELL_SIZE + PAD * 2 + CELL_SIZE * VAL, 0xFFD700,
	"Press SPACE to start the game");
	mlx_hook(win->win_ptr, 2, 0, key_hook, win);
	mlx_hook(win->win_ptr, 17, 1L << 17, exit_x, 0);
	mlx_loop(win->mlx_ptr);
	return (0);
}
