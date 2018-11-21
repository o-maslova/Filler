/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_staff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <omaslova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:51:52 by omaslova          #+#    #+#             */
/*   Updated: 2018/11/21 14:52:11 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		clear_list(t_coords *list)
{
	t_coords	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

t_coords	*node_create(int x, int y, int sum)
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

void		add_node(t_coords **list, t_coords *new)
{
	if (!(*list))
	{
		*list = new;
		return ;
	}
	new->next = *list;
	*list = new;
}

void		change(t_coords *coord_1, t_coords *coord_2)
{
	int change;

	change = coord_1->sum;
	coord_1->sum = coord_2->sum;
	coord_2->sum = change;
	change = coord_1->x;
	coord_1->x = coord_2->x;
	coord_2->x = change;
	change = coord_1->y;
	coord_1->y = coord_2->y;
	coord_2->y = change;
}

t_coords	*sort_list(t_coords *list)
{
	t_coords *tmp;
	t_coords *tmp_2;

	tmp = list;
	while (tmp->next)
	{
		tmp_2 = list;
		while (tmp_2->next)
		{
			if (tmp_2->sum > tmp_2->next->sum && tmp_2->next->x > 0)
			{
				change(tmp_2, tmp_2->next);
			}
			else if (tmp_2->sum == tmp_2->next->sum &&
				tmp_2->x > tmp_2->next->x)
			{
				change(tmp_2, tmp_2->next);
			}
			tmp_2 = tmp_2->next;
		}
		tmp = tmp->next;
	}
	return (list);
}
