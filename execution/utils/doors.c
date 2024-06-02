/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:46:04 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/02 19:35:05 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	upadte_values(t_data *data)
{
	if (data->doors->isopen == 0)
	{
		data->doors->isopen = 1;
		data->doors->current_cell = 'O';
	}
	else
	{
		data->doors->isopen = 0;
		data->doors->current_cell = 'D';
	}
}

int	check_closest_door(t_data *data, int index_x, int index_y)
{
	if (data->map[index_y + 1][index_x] == 'D'
		|| data->map[index_y - 1][index_x] == 'D'
		|| data->map[index_y][index_x + 1] == 'D'
		|| data->map[index_y][index_x - 1] == 'D')
		return (1);
	return (0);
}

int	check_if_compatibles(t_data *data, int index_x, int index_y)
{
	if ((data->doors->doorx == index_x && data->doors->doory == index_y + 1)
		|| (data->doors->doorx == index_x && data->doors->doory == index_y - 1)
		|| (data->doors->doorx == index_x + 1 && data->doors->doory == index_y)
		|| (data->doors->doorx == index_x - 1 && data->doors->doory == index_y))
		return (1);
	return (0);
}

t_doors	*get_door(t_data *data, int indexX, int indexY)
{
	t_doors	*head;

	if (!data->doors)
		return (NULL);
	head = data->doors;
	while (head)
	{
		if (head->doorx == indexX && head->doory == indexY)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	find_doors(t_data *data)
{
	int		x;
	int		y;
	t_doors	*head;
	t_doors	*new_door;

	head = NULL;
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'D')
			{
				if (!head)
					head = add_new(y, x);
				else
				{
					new_door = add_new(y, x);
					add_back(&head, new_door);
				}
			}
		}
	}
	data->doors = head;
}
