#include "filler.h"

t_coords        *sort_list(t_coords *list)
{
    int         change;
    t_coords    *tmp;
    t_coords    *tmp_2;

    tmp = list;
    while (tmp->next)
    {
        tmp_2 = list;
        while (tmp_2->next)
        {
            if (tmp_2->sum > tmp_2->next->sum && tmp_2->sum != 0)
            {
                change = tmp_2->sum;
                tmp_2->sum = tmp_2->next->sum;
                tmp_2->next->sum = change;
            }
            tmp_2 = tmp_2->next;
        }
        tmp = tmp->next;
    }
    return (list);
}

void        print_sum(t_coords *list)
{
    int i;

    i = 0;
    while (list)
    {
        dprintf(3, "%d node = %d, ", i++, list->sum);
        list = list->next;
    }
    dprintf(3, "\n");
}

t_coords    *node_create(int x, int y, int sum)
{
    t_coords *coords;

    coords = NULL;
    if ((coords = (t_coords *)malloc(sizeof(t_coords))))
    {
        coords->x = x;
        coords->y = y;
        coords->sum = sum;
        coords->next = NULL;
    }
    return (coords);
}

void        push_front(t_coords **list, t_coords *new)
{
    dprintf(3, "new->x = %d, new->y = %d, new->sum = %d\n", new->x, new->y, new->sum);
    if (!(*list))
    {
        *list = node_create(new->x, new->y, new->sum);
        return ;
    }
    new->next = *list;
    *list = new;
}

void        push_back(t_coords **list, t_coords *new)
{
    t_coords	*tmp;

	tmp = NULL;
	if (!(*list))
		*list = node_create(new->x, new->y, new->sum);
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int		down(t_data *data, int row, int col, int res)
{
	int star_i[2]; //iterators for piece elements (star_i[0] = i, star_j[1] = j)
	int starAmount;
    int mtrx_col;

	star_i[0] = -1;
	starAmount = 0;
 	dprintf(3, "row = %d, col = %d\n", row, col);
	while (++star_i[0] < data->x_pc)
	{
		star_i[1] = -1;
		mtrx_col = col - 1;
		while (++star_i[1] < data->y_pc && ++mtrx_col)
		{
            if (starAmount > 1 || data->mtrx[row][mtrx_col].isEnemy)
				return (0);
			if (data->pc[star_i[0]][star_i[1]] == '*' && starAmount <= 1)
			{
				if (data->mtrx[row][mtrx_col].isPlayer || data->mtrx[row][mtrx_col].isEnemy)
					starAmount++;
				if (!data->mtrx[row][mtrx_col].isEnemy)
					res += data->mtrx[row][mtrx_col].length;
			}
 		}
		row++;
	}
    return (res);
}

void		star_min_dist(t_data *data, int row, int col, t_coords **new)
{
	int         i;
	int         j;
    int         tmp;
    int         res;
  
	i = -1;
    res = 0;
    *new = node_create(0, 0, 255);
	while (++i < data->x_pc)
	{
		j = -1;
		while (++j < data->y_pc)
		{
			if (data->pc[i][j] == '*')
			{
				if ((tmp = down(data, row - i, col - j, res)) < (*new)->sum && tmp != 0)
				{
                    (*new)->x = row - i;
                    (*new)->y = col - j;
                    (*new)->sum = tmp;
				}
                dprintf(3, "TMP = %d, RES = %d, star_i = %d, star_j = %d\n", tmp, (*new)->sum, i, j);
				if ((tmp = down(data, row - i - data->x_pc + 1, col - j, res)) < (*new)->sum && tmp != 0)
				{
			    	(*new)->x = row - i - data->x_pc + 1;
					(*new)->y = col - j;
					(*new)->sum = tmp;
				}
                dprintf(3, "TMP = %d, RES = %d, star_i = %d, star_j = %d\n", tmp, (*new)->sum, i, j);
                // if (tmp == 0)
                // {
                //     (*new)->x = 0;
				// 	(*new)->y = 0;
				// 	(*new)->sum = 0;
                // }
                // dprintf(3, "TMP = %d, RES = %d, star_i = %d, star_j = %d\n", tmp, (*new)->sum, i, j);
			}
		}
	}
    	// dprintf(3, "row = %d, column = %d\n", row, col);
}

void	search_position(t_data *data, t_coords *list)
{
	int i;
	int j;
	int min;
    t_coords *new;
 
	i = -1;
    min = 255;
    new = NULL;
	data->coords = (t_coords *)ft_memalloc(sizeof(t_coords));
	while (++i < data->row)
	{
		j = -1;
		while (++j < data->column)
		{
			if (data->mtrx[i][j].isPlayer)
			{
                dprintf(3, "---NEXT CELL---\n");
                star_min_dist(data, i, j, &new);
 				if (new->sum < min && new->sum != 0)
				{
					min = new->sum;
				}
                push_front(&list, new);
			}
		}
	}
    list = sort_list(list);
    data->coords->x = list->x;
    data->coords->y = list->y;
    print_sum(list);
	// if (tmp == 0)
	// 	ft_bzero(data->coords, sizeof(t_coords));
}
