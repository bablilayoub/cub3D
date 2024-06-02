/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:46:04 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/02 15:08:00 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

t_doors	*getLast(t_doors *doors)
{
    t_doors	*last_door;

    last_door = doors;
    while (last_door->next)
        last_door = last_door->next;
    return (last_door);
}

void	addBack(t_doors **doors, t_doors *newDoor)
{
	t_doors	*last_door;

	if (doors)
	{
		if (*doors)
		{
			last_door = getLast(*doors);
			last_door->next = newDoor;
		}
		else
			*doors = newDoor;
	}
}
t_doors	*addNew(int y, int x)
{
	t_doors	*door;

	door = (t_doors *)malloc(sizeof(t_doors));
	if (!door)
		return (NULL);
    door->next = NULL;
    door->doorX = x;
    door->doorY = y;
	door->isOpen = 0;
	door->current_cell = 'D';
	return (door);
}