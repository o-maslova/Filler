/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_staff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <omaslova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:45:52 by omaslova          #+#    #+#             */
/*   Updated: 2018/11/21 17:45:57 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	clear_mtrx(t_data *data, int *counter)
{
	int i;
	int j;

	i = 0;
	while (i < ROW)
	{
		j = 0;
		while (j < COLUMN)
		{
			data->mtrx[i][j].length = 0;
			++j;
		}
		++i;
	}
	data->coords->x = 0;
	data->coords->y = 0;
	data->star_amount = 0;
	*counter = 0;
}

void	ft_mtrxdel(t_point **arr, int row)
{
	int i;

	i = 0;
	while (i < row)
	{
		free(arr[i]);
		arr[i] = NULL;
		++i;
	}
	free(arr);
	arr = NULL;
}
