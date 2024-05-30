/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallhits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:30:22 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/30 14:30:32 by alaalalm         ###   ########.fr       */
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