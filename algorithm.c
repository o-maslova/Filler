#include "filler.h"

void			find_first_col(t_data *data)
{
	int i;
	int j;

	i = 0;
	data->firstMinStar[0] = data->x_pc;
	data->firstMinStar[1] = data->y_pc;
	while (i < data->x_pc)
	{
		j = 0;
		while (j < data->y_pc)
		{
			if (data->pc[i][j] == '*')
			{
				if (j < data->firstMinStar[1])
					data->firstMinStar[1] = j;
				if (i < data->firstMinStar[0])
					data->firstMinStar[0] = i;
			}
			++j;
		}
		++i;
	}
}

int				algorithm(t_data *data, int row, int col, int res)
{
	int star_i[2]; //iterators for piece elements (star_i[0] = i, star_j[1] = j)
	int starAmount;
    int temp;
	
	star_i[0] = data->firstMinStar[0];
	starAmount = 0;
 	// dprintf(3, "first column with star = %d\n", data->firstMinStar[1]);
	while (star_i[0] < data->x_pc)
	{
		star_i[1] = data->firstMinStar[1];
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
				// dprintf(3, "*** %d res = %d, i = %d, j = %d***\n", k++, res, star_i[0], star_i[1]);
			}
			++temp;
			++star_i[1];
 		}
		++star_i[0];
		++row;
	}
	// dprintf(3, "*** = %d, i = %d, j = %d***\n", res, star_i[0], star_i[1]);
	res = starAmount == 0 ? 0 : res;
    return (res);
}

// void			choose_coords(t_data *data, t_coords *list)
// {
// 	int		i;
// 	int		j;
// 	int		min[2];
  
// 	i = -1;
// 	data->coords->x = list->x;
//     data->coords->y = list->y;
// 	while (++i < data->x_pc)
// 	{
// 		j = -1;
// 		while (++j < data->y_pc)
// 		{
// 			if (data->pc[i][j] == '*')
// 			{
// 				min[0] = i;
// 				min[1] = j;
// 			}
// 		}
// 	}
// 	dprintf(3, "min[0] = %d, min[1] = %d\n", min[0], min[1]);
// 	if (!list)
// 	{
// 		data->coords->x = 0;
//     	data->coords->y = 0;
// 		return ;
// 	}
// 	// if ((data->coords->x + min[0] >= data->row || data->coords->y + min[1] >= data->column) && list)
// 	// 	return (choose_coords(data, list->next));
// }

void			search_position(t_data *data, t_coords *list)
{	
	int i;
	int j;
	int tmp;
	int res;
    t_coords *new;
 
	i = -1;
	res = 0;
    new = NULL;
	data->coords = (t_coords *)ft_memalloc(sizeof(t_coords));
	find_first_col(data);
	while (++i < data->row)
	{
		j = -1;
		while (++j < data->column)
		{
			if ((tmp = algorithm(data, i, j, res)) > 0)
			{
				new = node_create(i - data->firstMinStar[0], j - data->firstMinStar[1], tmp);
				add_node(&list, new);
				dprintf(3, "RES = %d, new->x = %d, new->y = %d\n", new->sum, new->x, new->y);
			}
		}
	}
	if (!list)
	{
		data->coords->x = 0;
    	data->coords->y = 0;
	}
	else
	{
		dprintf(3, "---WITHOUT SORT---\n");
		print_sum(list);
		list = sort_list(list);
		data->coords->x = list->x;
	    data->coords->y = list->y;
	//choose_coords(data, list);
		dprintf(3, "---WITH SORT---\n");
  		print_sum(list);
	}
}
