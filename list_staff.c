#include "filler.h"

void	clear_list(t_coords **list)
{
	while (*list)
	{
		free(*list);
		*list = (*list)->next;
	}
	*list = NULL;
}

void            change(int *num, int *numToChange)
{
    int change;

    change = *num;
    *num = *numToChange;
    *numToChange = change;
}

t_coords        *sort_list(t_coords *list)
{
    t_coords    *tmp;
    t_coords    *tmp_2;

    tmp = list;
    while (tmp->next)
    {
        tmp_2 = list;
        while (tmp_2->next)
        {
            if (tmp_2->sum > tmp_2->next->sum && tmp_2->next->x > 0)
            {
                change(&(tmp_2->sum), &(tmp_2->next->sum));
                change(&(tmp_2->x), &(tmp_2->next->x));
                change(&(tmp_2->y), &(tmp_2->next->y));
            }
            else if (tmp_2->sum == tmp_2->next->sum && tmp_2->x > tmp_2->next->x)
            {
                change(&(tmp_2->sum), &(tmp_2->next->sum));
                change(&(tmp_2->x), &(tmp_2->next->x));
                change(&(tmp_2->y), &(tmp_2->next->y));
            }
            // else if ((tmp_2->y < 0 && tmp_2->next->y > 0) || (tmp_2->x < 0 && tmp_2->next->x))
            // {
            //     change(&(tmp_2->sum), &(tmp_2->next->sum));
            //     change(&(tmp_2->x), &(tmp_2->next->x));
            //     change(&(tmp_2->y), &(tmp_2->next->y));
            // }
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
        dprintf(3, "%d node = %d, x = %d, y = %d; ", i++, list->sum, list->x, list->y);
        list = list->next;
    }
    dprintf(3, "\n");
}

t_coords    *node_create(int x, int y, int sum)
{
    t_coords *coords;

    coords = NULL;
    if ((coords = (t_coords *)ft_memalloc(sizeof(t_coords))))
    {
        coords->x = x;
        coords->y = y;
        coords->sum = sum;
        coords->next = NULL;
    }
    return (coords);
}

void        add_node(t_coords **list, t_coords *new)
{
    if (!(*list))
    {
        *list = node_create(new->x, new->y, new->sum);
        return ;
    }
    new->next = *list;
    *list = new;
}
