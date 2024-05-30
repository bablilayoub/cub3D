/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallhits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:30:22 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/30 14:42:29 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void findHorizWallHit(t_data *data, t_ray *ray)
{
	while ( ray->nextHorzTouchX >= 0 &&  ray->nextHorzTouchX <= (data->map_width * TILE_SIZE)
		&& ray->nextHorzTouchY >= 0 && ray->nextHorzTouchY <= (data->map_height * TILE_SIZE))
	{

		ray->xToCheck =  ray->nextHorzTouchX;
		if (ray->isRayFacingUp)
			ray->yToCheck = ray->nextHorzTouchY - 1;
		else
			ray->yToCheck = ray->nextHorzTouchY;
        if (has_wall_at(data, ray->xToCheck, ray->yToCheck)) {
            ray->horzWallHitX =  ray->nextHorzTouchX;
            ray->horzWallHitY = ray->nextHorzTouchY;
            // ray->horzWallContent = (int)data->map[(int)floor(ray->yToCheck / TILE_SIZE)][(int)floor(ray->xToCheck / TILE_SIZE)];
            ray->foundHorzWallHit = true;
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
		&& ray->nextVertTouchY >= 0 && ray->nextVertTouchY <= (data->map_height * TILE_SIZE)) {
		
		ray->yToCheck = ray->nextVertTouchY;
		if (ray->isRayFacingLeft)
			ray->xToCheck = ray->nextVertTouchX - 1;
		else
			ray->xToCheck = ray->nextVertTouchX;
		
		if (has_wall_at(data, ray->xToCheck, ray->yToCheck)) {
			ray->vertWallHitX = ray->nextVertTouchX;
			ray->vertWallHitY = ray->nextVertTouchY;
			// ray->vertWallContent = (int)data->map[(int)floor(ray->yToCheck / TILE_SIZE)][(int)floor(ray->xToCheck / TILE_SIZE)];
			ray->foundVertWallHit = true;
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

	mapGridIndexX = floor(x) / TILE_SIZE;
	mapGridIndexY = floor(y) / TILE_SIZE;
	if (mapGridIndexX < 0 || mapGridIndexX >= data->map_width || mapGridIndexY < 0 || mapGridIndexY >= data->map_height)
		return (1);
	return (data->map[mapGridIndexY][mapGridIndexX] == '1');
}

double distance_between_points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}