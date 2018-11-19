#include "filler.h"

int				algorithm(t_data *data, int row, int col, int res)
{
	int star_i[2]; //iterators for piece elements (star_i[0] = i, star_j[1] = j)
	int starAmount;
    int temp;

	star_i[0] = 0;
	starAmount = 0;
 	// dprintf(3, "row = %d, col = %d\n", row, col);
	while (star_i[0] < data->x_pc)
	{
		star_i[1] = 0;
		temp = col;
		while (star_i[1] < data->y_pc)
		{
			if (data->pc[star_i[0]][star_i[1]] == '*')
			{
				if (row >= data->row || temp >= data->column)
					return (0);
				if (data->mtrx[row][temp].isEnemy)
					return (0);
				if (data->mtrx[row][temp].isPlayer)
				{
					++starAmount;
					if (starAmount > 1)
						return (0);
				}
				res += data->mtrx[row][temp].length;
			}
			++star_i[1];
			++temp;
 		}
		++star_i[0];
		++row;
	}
	res = starAmount == 0 ? 0 : res;
	// dprintf(3, "res = %d\n", res);
    return (res);
}

t_coords		*star_min_dist(t_data *data, int row, int col, t_coords *new)
{
    int         tmp;
    int         res;
  
    res = 0;
  	// while (++i < data->x_pc)
	// {
	// 	j = 0;
	// 	while (j < data->y_pc)
	// 		if (data->pc[i][j] == '*')
	// 			break ;
	// 		else
	// 			j++;
	// 	if (j < data->y_pc)
	// 		break ;
	// }
	// dprintf(3, "j = %d\n", j);
	
	if ((tmp = algorithm(data, row, col, res)) > 0)
	{
		new = node_create(row, col, tmp);
		dprintf(3, "RES = %d, new->x = %d, new->y = %d\n", new->sum, new->x, new->y);
	}
	else
		new = NULL;
  	return (new);
   	// dprintf(3, "row = %d, column = %d\n", row, col);
}

void			choose_coords(t_data *data, t_coords *list)
{
	int		i;
	int		j;
	int		min[2];
  
	i = -1;
	data->coords->x = list->x;
    data->coords->y = list->y;
	while (++i < data->x_pc)
	{
		j = -1;
		while (++j < data->y_pc)
		{
			if (data->pc[i][j] == '*')
			{
				min[0] = i;
				min[1] = j;
			}
		}
	}
	dprintf(3, "min[0] = %d, min[1] = %d\n", min[0], min[1]);
	if (!list)
	{
		data->coords->x = 0;
    	data->coords->y = 0;
		return ;
	}
	// if ((data->coords->x + min[0] >= data->row || data->coords->y + min[1] >= data->column) && list)
	// 	return (choose_coords(data, list->next));
}

void			search_position(t_data *data, t_coords *list)
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
	dprintf(3, "---WITHOUT SORT---\n");
	print_sum(list);
	list = sort_list(list);
	data->coords->x = list->x;
    data->coords->y = list->y;
	//choose_coords(data, list);
	dprintf(3, "---WITH SORT---\n");
    print_sum(list);
}
