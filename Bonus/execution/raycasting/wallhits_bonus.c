/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallhits_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:30:22 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/06 21:25:59 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution_bonus.h"

void	findhorizwallhit(t_data *data, t_ray *ray)
{
	while (ray->nexthorztouchx >= 0
		&& ray->nexthorztouchx <= (data->map_width * TILE_SIZE)
		&& ray->nexthorztouchy >= 0
		&& ray->nexthorztouchy <= (data->map_height * TILE_SIZE))
	{
		if (has_wall_at(data, ray->nexthorztouchx, ray->nexthorztouchy))
		{
			ray->washithorizontal = true;
			ray->horzwallhitx = ray->nexthorztouchx;
			ray->horzwallhity = ray->nexthorztouchy;
			break ;
		}
		else
		{
			ray->nexthorztouchx += ray->xstep;
			ray->nexthorztouchy += ray->ystep;
		}
	}
}

void	findverticalwallhit(t_data *data, t_ray *ray)
{
	while (ray->nextverttouchx >= 0
		&& ray->nextverttouchx <= (data->map_width * TILE_SIZE)
		&& ray->nextverttouchy >= 0
		&& ray->nextverttouchy <= (data->map_height * TILE_SIZE))
	{
		if (has_wall_at(data, ray->nextverttouchx, ray->nextverttouchy))
		{
			ray->washitvertical = true;
			ray->vertwallhitx = ray->nextverttouchx;
			ray->vertwallhity = ray->nextverttouchy;
			break ;
		}
		else
		{
			ray->nextverttouchx += ray->xstep;
			ray->nextverttouchy += ray->ystep;
		}
	}
}

int	has_wall_at(t_data *data, double x, double y)
{
	int		gridindex_x;
	int		gridindex_y;
	t_doors	*door;

	if (x < 0 || x > data->map_width * TILE_SIZE
		|| y < 0 || y > data->map_height * TILE_SIZE)
		return (1);
	gridindex_x = floor(x / TILE_SIZE);
	gridindex_y = floor(y / TILE_SIZE);
	door = get_door(data, gridindex_x, gridindex_y);
	if (gridindex_x < 0 || gridindex_x >= data->map_width
		|| gridindex_y < 0 || gridindex_y >= data->map_height)
		return (1);
	return (data->map[gridindex_y][gridindex_x] == '1'
		|| (data->map[gridindex_y][gridindex_x] == 'D'
		&& door && door->current_cell == 'D'));
}

double	vector_lenght(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
