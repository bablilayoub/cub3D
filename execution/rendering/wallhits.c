/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallhits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:30:22 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/02 15:18:28 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void findHorizWallHit(t_data *data, t_ray *ray)
{
	while ( ray->nextHorzTouchX >= 0 &&  ray->nextHorzTouchX <= (data->map_width * TILE_SIZE)
		&& ray->nextHorzTouchY >= 0 && ray->nextHorzTouchY <= (data->map_height * TILE_SIZE))
	{
        if (has_wall_at(data, ray->nextHorzTouchX, ray->nextHorzTouchY))
		{
            ray->wasHitHorizontal = true;
            ray->horzWallHitX =  ray->nextHorzTouchX;
            ray->horzWallHitY = ray->nextHorzTouchY;
            break;
        } else {
            ray->nextHorzTouchX += ray->xstep;
            ray->nextHorzTouchY += ray->ystep;
        }
	}
}

void findVerticalWallHit(t_data *data, t_ray *ray)
{
	while (ray->nextVertTouchX >= 0 && ray->nextVertTouchX <= (data->map_width * TILE_SIZE)
		&& ray->nextVertTouchY >= 0 && ray->nextVertTouchY <= (data->map_height * TILE_SIZE)) 
	{
		if (has_wall_at(data, ray->nextVertTouchX, ray->nextVertTouchY)) {
			ray->wasHitVertical = true;
			ray->vertWallHitX = ray->nextVertTouchX;
			ray->vertWallHitY = ray->nextVertTouchY;
			break;
		} else {
			ray->nextVertTouchX += ray->xstep;
			ray->nextVertTouchY += ray->ystep;
		}
	}
}

int has_wall_at(t_data *data, double x, double y)
{
	int mapGridIndexX;
	int mapGridIndexY;

	mapGridIndexX = floor(x / TILE_SIZE);
	mapGridIndexY = floor(y / TILE_SIZE);
	if (mapGridIndexX < 0 || mapGridIndexX >= data->map_width || mapGridIndexY < 0 || mapGridIndexY >= data->map_height)
		return (1);
	return (data->map[mapGridIndexY][mapGridIndexX] == '1' || (data->map[mapGridIndexY][mapGridIndexX] == 'D' && get_door(data, mapGridIndexX, mapGridIndexY)->current_cell == 'D'));
}

double vector_lenght(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}