#include "view.h"

void	pixel_put_img(t_win *win, int x, int y, int colour)
{
	if (x < HEIGTH || y < WIDTH)
	{
		colour = mlx_get_color_value(win->mlx_ptr, colour);
		ft_memcpy(win->img + 4 * WIDTH * y + x * 4, &colour, sizeof(int));
	}
}

void	draw_square(t_win *win, int row, int column, int color)
{
	int i;
	int j;
	int i_cell;
	int j_cell;

	i_cell = (row * CELL_SIZE);
	j_cell = (column * CELL_SIZE);
	i = i_cell + 1;
	while (i < i_cell + CELL_SIZE - 1)
	{
		j = j_cell + 1;
		while (j < j_cell + CELL_SIZE - 1)
		{
			pixel_put_img(win, i + PAD, j + PAD, color);
			++j;
		}
		++i;
	}
}

void	draw_matrix(t_win *win)
{	
	int i;
	int j;

	i = 0;
	while (i < VIEW_ROW)
	{
		j = 0;
		while (j < VIEW_COLUMN)
		{
			if (win->matrix[i][j] == g_player)
				draw_square(win, j, i, 0x00FF00);
			else if (win->matrix[i][j] == g_enemy)
				draw_square(win, j, i, 0xFF0000);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
}

void	continue_draw(t_win *win, int i, int j)
{
	int i_cell;
	int j_cell;

	i_cell = i;
	while (i_cell <= i + CELL_SIZE)
	{
		j_cell = j;
		if (i_cell == i || i_cell == i + CELL_SIZE)
		{
			while (j_cell <= j + CELL_SIZE)
			{
				pixel_put_img(win, i_cell + PAD, j_cell + PAD, 0xFFFFFF);
				++j_cell;
			}
		}
		else
		{
			pixel_put_img(win, i_cell + PAD, j_cell + PAD, 0xFFFFFF);
			pixel_put_img(win, i_cell + PAD, j + CELL_SIZE + PAD, 0xFFFFFF);
		}
		++i_cell;
	}
}

void	draw_field(t_win *win)
{
	int i;
	int j;

	i = 0;
	draw_players(win);
	while (i < VIEW_COLUMN * 48)
	{
		j = 0;
		while (j < VIEW_ROW * 48)
		{
			continue_draw(win, i, j);
			j += CELL_SIZE;
		}
		i += CELL_SIZE;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
}
