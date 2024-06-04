/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:37:59 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/04 19:00:55 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution_bonus.h"

void	horizontalray(t_data *data, t_ray *ray, double rayAngle)
{
	ray->washithorizontal = false;
	ray->horzwallhitx = 0;
	ray->horzwallhity = 0;
	ray->yintercept = floor((data->player->pos_y / TILE_SIZE)) * TILE_SIZE;
	if (ray->israyfacingdown)
		ray->yintercept += TILE_SIZE;
	ray->xintercept = data->player->pos_x
		+ (ray->yintercept - data->player->pos_y) / tan(rayAngle);
	ray->ystep = TILE_SIZE;
	if (ray->israyfacingup)
		ray->ystep *= -1;
	ray->xstep = TILE_SIZE / tan(rayAngle);
	if (ray->israyfacingleft && ray->xstep > 0)
		ray->xstep *= -1;
	if (ray->israyfacingright && ray->xstep < 0)
		ray->xstep *= -1;
	ray->nexthorztouchx = ray->xintercept;
	ray->nexthorztouchy = ray->yintercept;
	if (data->rays->israyfacingup)
		ray->nexthorztouchy--;
	findhorizwallhit(data, ray);
}

void	verticalray(t_data *data, t_ray *ray, double rayAngle)
{
	ray->washitvertical = false;
	ray->vertwallhitx = 0;
	ray->vertwallhity = 0;
	ray->xintercept = floor(data->player->pos_x / TILE_SIZE) * TILE_SIZE;
	if (ray->israyfacingright)
		ray->xintercept += TILE_SIZE;
	ray->yintercept = data->player->pos_y
		+ (ray->xintercept - data->player->pos_x) * tan(rayAngle);
	ray->xstep = TILE_SIZE;
	if (ray->israyfacingleft)
		ray->xstep *= -1;
	ray->ystep = TILE_SIZE * tan(rayAngle);
	if (ray->israyfacingup && ray->ystep > 0)
		ray->ystep *= -1;
	if (ray->israyfacingdown && ray->ystep < 0)
		ray->ystep *= -1;
	ray->nextverttouchx = ray->xintercept;
	ray->nextverttouchy = ray->yintercept;
	if (ray->israyfacingleft)
		ray->nextverttouchx--;
	findverticalwallhit(data, ray);
}

void	distance(t_data *data, t_ray *ray)
{
	if (ray->washithorizontal)
		ray->horzhitdistance = vector_lenght(data->player->pos_x,
				data->player->pos_y, ray->horzwallhitx, ray->horzwallhity);
	else
		ray->horzhitdistance = INT_MAX;
	if (ray->washitvertical)
		ray->verthitdistance = vector_lenght(data->player->pos_x,
				data->player->pos_y, ray->vertwallhitx, ray->vertwallhity);
	else
		ray->verthitdistance = INT_MAX;
	if (ray->verthitdistance < ray->horzhitdistance)
	{
		ray->distance = ray->verthitdistance;
		ray->wallhitx = ray->vertwallhitx;
		ray->wallhity = ray->vertwallhity;
		ray->washitvertical = true;
	}
	else
	{
		ray->distance = ray->horzhitdistance;
		ray->wallhitx = ray->horzwallhitx;
		ray->wallhity = ray->horzwallhity;
		ray->washitvertical = false;
	}
}

void	castray(t_data *data, double rayAngle)
{
	t_ray	*ray;

	ray = data->rays;
	rayAngle = normalize_angle(rayAngle);
	ray->israyfacingdown = rayAngle > 0 && rayAngle < M_PI;
	ray->israyfacingup = !ray->israyfacingdown;
	ray->israyfacingright = rayAngle < (0.5 * M_PI) || rayAngle > (1.5 * M_PI);
	ray->israyfacingleft = !ray->israyfacingright;
	horizontalray(data, ray, rayAngle);
	verticalray(data, ray, rayAngle);
	distance(data, ray);
}
