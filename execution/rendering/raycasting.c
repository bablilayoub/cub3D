/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:37:59 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/01 21:12:42 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void horizontalRay(t_data *data, t_ray *ray, double rayAngle)
{
	ray->wasHitHorizontal = false;
    ray->horzWallHitX = 0;
    ray->horzWallHitY = 0;
    ray->horzWallContent = 0;

    ray->yintercept = floor((data->player->posY / TILE_SIZE)) * TILE_SIZE;
    if (ray->isRayFacingDown)
		ray->yintercept += TILE_SIZE;
	
    ray->xintercept =  data->player->posX + (ray->yintercept - data->player->posY) / tan(rayAngle);
    ray->ystep = TILE_SIZE;
	if (ray->isRayFacingUp)
		ray->ystep *= -1;

    ray->xstep = TILE_SIZE / tan(rayAngle);
    if (ray->isRayFacingLeft && ray->xstep > 0)
		ray->xstep *= -1;
    if (ray->isRayFacingRight && ray->xstep < 0)
		ray->xstep *= -1;

    ray->nextHorzTouchX = ray->xintercept;
    ray->nextHorzTouchY = ray->yintercept;
    findHorizWallHit(data, ray);
}

void verticalRay(t_data *data, t_ray *ray, double rayAngle)
{
	ray->wasHitVertical = false;
	ray->vertWallHitX = 0;
	ray->vertWallHitY = 0;
	ray->vertWallContent = 0;

	ray->xintercept = floor(data->player->posX / TILE_SIZE) * TILE_SIZE;
	if (ray->isRayFacingRight)
		ray->xintercept += TILE_SIZE;
	ray->yintercept = data->player->posY + (ray->xintercept - data->player->posX) * tan(rayAngle);

	ray->xstep = TILE_SIZE;
	if (ray->isRayFacingLeft)
		ray->xstep *= -1;

	ray->ystep = TILE_SIZE * tan(rayAngle);
	if (ray->isRayFacingUp && ray->ystep > 0)
		ray->ystep *= -1;
	if (ray->isRayFacingDown && ray->ystep < 0)
		ray->ystep *= -1;

	ray->nextVertTouchX = ray->xintercept;
	ray->nextVertTouchY = ray->yintercept;
	findVerticalWallHit(data, ray);
}

void distance(t_data *data, t_ray *ray)
{
	if (ray->wasHitHorizontal)
		ray->horzHitDistance = vector_lenght(data->player->posX, data->player->posY, ray->horzWallHitX, ray->horzWallHitY);
	else
		ray->horzHitDistance = INT_MAX;

	if (ray->wasHitVertical)
		ray->vertHitDistance = vector_lenght(data->player->posX, data->player->posY, ray->vertWallHitX, ray->vertWallHitY);
	else
		ray->vertHitDistance = INT_MAX;
    if (ray->vertHitDistance < ray->horzHitDistance)
	{
        ray->distance = ray->vertHitDistance;
		ray->wallHitX = ray->vertWallHitX;
		ray->wallHitY = ray->vertWallHitY;
		// ray->wallHitContent = ray->vertWallContent;
		ray->wasHitVertical = true;
    } 
	else 
	{
		ray->distance = ray->horzHitDistance;
		ray->wallHitX = ray->horzWallHitX;
		ray->wallHitY = ray->horzWallHitY;
		// ray->wallHitContent = ray->horzWallContent;
		ray->wasHitVertical = false;
	}
}
void castRay(t_data *data, double rayAngle)
{	
	t_ray *ray;

	ray = data->rays;
    rayAngle = normalize_angle(rayAngle);
    ray->isRayFacingDown = rayAngle > 0 && rayAngle < M_PI;
    ray->isRayFacingUp = !ray->isRayFacingDown;
    ray->isRayFacingRight = rayAngle < (0.5 * M_PI) || rayAngle > (1.5 * M_PI);
    ray->isRayFacingLeft = !ray->isRayFacingRight;
    horizontalRay(data, ray, rayAngle);
	verticalRay(data, ray, rayAngle);
	distance(data, ray);
	// line(data, data->player->posX * MINIMAP_SCALE_FACTOR,
	// 		   data->player->posY * MINIMAP_SCALE_FACTOR,
	// 		        ray->wallHitX * MINIMAP_SCALE_FACTOR,
	// 				ray->wallHitY * MINIMAP_SCALE_FACTOR);
}