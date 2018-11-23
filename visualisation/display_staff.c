#include "view.h"

void	draw_players(t_win *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, PAD, 10, 0xFFD700, "Your player is green");
	mlx_string_put(win->mlx_ptr, win->win_ptr, PAD, 40, 0xFFD700, "Enemy player is red");
}

void	display_winner(t_win *win, char *line)
{
	int		score[2];
	char	*tmp;

	score[0] = ft_atoi(line + 10);
	get_next_line(g_fd_m, &tmp);
	score[1] = ft_atoi(tmp + 10);
	// dprintf(g_fd, "num1 = %d, num2 = %d\n", score[0], score[1]);
	// dprintf(g_fd, "player = %c\n", ft_tolower(*(line + 3)));
	if (ft_tolower(*(line + 3)) == g_player)
	{
		if (score[0] > score[1])
			mlx_string_put(win->mlx_ptr, win->win_ptr, PAD, VIEW_COLUMN * CELL_SIZE + PAD + 10, 0xFFD700, "YOU WIN!");
		else
			mlx_string_put(win->mlx_ptr, win->win_ptr, PAD, VIEW_COLUMN * CELL_SIZE + PAD + 10, 0xFFD700, "YOU LOSE!");
	}
	else
	{
		if (score[1] > score[0])
			mlx_string_put(win->mlx_ptr, win->win_ptr, PAD, VIEW_COLUMN * CELL_SIZE + PAD + 10, 0xFFD700, "YOU WIN!");
		else
			mlx_string_put(win->mlx_ptr, win->win_ptr, PAD, VIEW_COLUMN * CELL_SIZE + PAD + 10, 0xFFD700, "YOU LOSE!");
	}
	free(tmp);
}