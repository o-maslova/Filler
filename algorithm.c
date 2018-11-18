#include "filler.h"

int		algorithm(t_data *data, int row, int col, int res)
{
	int star_i[2]; //iterators for piece elements (star_i[0] = i, star_j[1] = j)
	int starAmount;
    int mtrx_col;

	star_i[0] = -1;
	starAmount = 0;
 	// dprintf(3, "row = %d, col = %d\n", row, col);
	while (++star_i[0] < data->x_pc)
	{
		star_i[1] = -1;
		mtrx_col = col - 1;
		while (++star_i[1] < data->y_pc && ++mtrx_col && row < data->row)
		{
            if (starAmount > 1 || data->mtrx[row][mtrx_col].isEnemy)
				return (0);
			if (data->pc[star_i[0]][star_i[1]] == '*' && starAmount <= 1 && mtrx_col < data->column)
			{
				starAmount = data->mtrx[row][mtrx_col].isPlayer ? starAmount + 1 : starAmount;
				res += data->mtrx[row][mtrx_col].length;
			}
 		}
		row++;
	}
	res = starAmount == 0 ? 0 : res;
	// dprintf(3, "res = %d\n", res);
    return (res);
}

t_coords		*star_min_dist(t_data *data, int row, int col, t_coords *new)
{
	int         i;
	int         j;
    int         tmp;
    int         res;
  
	i = -1;
    res = 0;
  	while (++i < data->x_pc)
	{
		j = 0;
		while (j < data->y_pc && data->pc[i][j] != '*')
			j++;
		if (j < data->y_pc)
			break ;
	}
	if ((tmp = algorithm(data, row - i, col - j, res)) > 0)
	{
		new = node_create(row - i, col - j, tmp);
		dprintf(3, "RES = %d, new->x = %d, new->y = %d\n", new->sum, new->x, new->y);
	}
	else
		new = NULL;
  	return (new);
   	// dprintf(3, "row = %d, column = %d\n", row, col);
}

void	search_position(t_data *data, t_coords *list)
{
	int i;
	int j;
    t_coords *new;
 
	i = -1;
    new = NULL;
	data->coords = (t_coords *)ft_memalloc(sizeof(t_coords));
	while (++i < data->row)
	{
		j = -1;
		while (++j < data->column)
		{
			// dprintf(3, "---NEXT CELL---\n");
            new = star_min_dist(data, i, j, new);
        	if (new != NULL)
				add_node(&list, new);
		}
	}
    list = sort_list(list);
    data->coords->x = list->x;
    data->coords->y = list->y;
    print_sum(list);
}
