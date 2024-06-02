/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:47:43 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/02 19:35:32 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

t_doors	*get_last(t_doors *doors)
{
	t_doors	*last_door;

	if (!doors)
		return (NULL);
	last_door = doors;
	while (last_door->next)
		last_door = last_door->next;
	return (last_door);
}

void	add_back(t_doors **doors, t_doors *newDoor)
{
	t_doors	*last_door;

	if (doors)
	{
		if (*doors)
		{
			last_door = get_last(*doors);
			last_door->next = newDoor;
		}
		else
			*doors = newDoor;
	}
}

t_doors	*add_new(int y, int x)
{
	t_doors	*door;

	door = (t_doors *)malloc(sizeof(t_doors));
	if (!door)
		return (NULL);
	door->next = NULL;
	door->doorx = x;
	door->doory = y;
	door->isopen = 0;
	door->current_cell = 'D';
	return (door);
}
