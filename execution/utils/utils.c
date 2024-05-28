/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:16:09 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/28 22:21:20 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

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

double normalize_angle(double angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

double distance_between_points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}