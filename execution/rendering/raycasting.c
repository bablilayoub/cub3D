/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:37:59 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/28 22:33:07 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void castRay(t_data *data, double rayAngle)
{
    rayAngle = normalize_angle(rayAngle);
    int isRayFacingDown = rayAngle > 0 && rayAngle < M_PI;
    int isRayFacingUp = !isRayFacingDown;
    int isRayFacingRight = rayAngle < (0.5 * M_PI) || rayAngle > (1.5 * M_PI);
    int isRayFacingLeft = !isRayFacingRight;
    
    double xintercept, yintercept;
    double xstep, ystep;

    int foundHorzWallHit = false;
    double horzWallHitX = 0;
    double horzWallHitY = 0;
    int horzWallContent = 0;

    yintercept = floor((data->player->posY / TILE_SIZE)) * TILE_SIZE;
    yintercept += isRayFacingDown ? TILE_SIZE : 0;

    xintercept =  data->player->posX + (yintercept - data->player->posY) / tan(rayAngle);

    ystep = TILE_SIZE;
    ystep *= isRayFacingUp ? -1 : 1;

    xstep = TILE_SIZE / tan(rayAngle);
    xstep *= (isRayFacingLeft && xstep > 0) ? -1 : 1;
    xstep *= (isRayFacingRight && xstep < 0) ? -1 : 1;

    double nextHorzTouchX = xintercept;
    double nextHorzTouchY = yintercept;
 
    // Increment xstep and ystep until we find a wall
    while (nextHorzTouchX >= 0 && nextHorzTouchX <= (data->map_width * TILE_SIZE) && nextHorzTouchY >= 0 && nextHorzTouchY <= (data->map_height * TILE_SIZE)) {
        double xToCheck = nextHorzTouchX;
        double yToCheck = nextHorzTouchY + (isRayFacingUp ? -1 : 0);
        
        if (has_wall_at(data, xToCheck, yToCheck)) {
            horzWallHitX = nextHorzTouchX;
            horzWallHitY = nextHorzTouchY;
            // horzWallContent = (int)data->map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
            foundHorzWallHit = true;
            break;
        } else {
            nextHorzTouchX += xstep;
            nextHorzTouchY += ystep;
        }
	}

	int foundVertWallHit = false;
	double vertWallHitX = 0;
	double vertWallHitY = 0;
	int vertWallContent = 0;

	xintercept = floor(data->player->posX / TILE_SIZE) * TILE_SIZE;
	xintercept += isRayFacingRight ? TILE_SIZE : 0;

	yintercept = data->player->posY + (xintercept - data->player->posX) * tan(rayAngle);

	xstep = TILE_SIZE;
	xstep *= isRayFacingLeft ? -1 : 1;

	ystep = TILE_SIZE * tan(rayAngle);
	ystep *= (isRayFacingUp && ystep > 0) ? -1 : 1;
	ystep *= (isRayFacingDown && ystep < 0) ? -1 : 1;

	double nextVertTouchX = xintercept;
	double nextVertTouchY = yintercept;

	while (nextVertTouchX >= 0 && nextVertTouchX <= (data->map_width * TILE_SIZE) && nextVertTouchY >= 0 && nextVertTouchY <= (data->map_height * TILE_SIZE)) {
		double xToCheck = nextVertTouchX + (isRayFacingLeft ? -1 : 0);
		double yToCheck = nextVertTouchY;
		
		if (has_wall_at(data, xToCheck, yToCheck)) {
			vertWallHitX = nextVertTouchX;
			vertWallHitY = nextVertTouchY;
			// vertWallContent = (int)data->map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
			foundVertWallHit = true;
			break;
		} else {
			nextVertTouchX += xstep;
			nextVertTouchY += ystep;
		}
	}
    double horzHitDistance = foundHorzWallHit
		? distance_between_points(data->player->posX, data->player->posY, horzWallHitX, horzWallHitY)
		: INT_MAX;
	double vertHitDistance = foundVertWallHit
		? distance_between_points(data->player->posX, data->player->posY, vertWallHitX, vertWallHitY)
		: INT_MAX;

    if (vertHitDistance < horzHitDistance) {
        data->rays->distance = vertHitDistance;
		data->rays->wallHitX = vertWallHitX;
		data->rays->wallHitY = vertWallHitY;
		data->rays->wallHitContent = vertWallContent;
		data->rays->wasHitVertical = true;

    } 
	else {
		data->rays->distance = horzHitDistance;
		data->rays->wallHitX = horzWallHitX;
		data->rays->wallHitY = horzWallHitY;
		data->rays->wallHitContent = horzWallContent;
		data->rays->wasHitVertical = false;
	}
	line(data, data->player->posX, data->player->posY, data->rays->wallHitX, data->rays->wallHitY);
}