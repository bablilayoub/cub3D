/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderwall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:06:33 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/31 16:17:38 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void renderWall(t_data *data, int rayId, int y, int wallHeight, int color)
{
    int i;
    int j;

    i = -1;
    while (++i < wallHeight)
    {
        j = -1;
        while (++j < 1)
            *(unsigned int *)(data->addr + ((y + i) * data->line_length + (rayId) * (data->bits_per_pixel / 8)) ) = color;
    }
}
void render_column(t_data *data, int rayId, double rayAngle, double distance)
{
	double projPlaneDistance;
	int wallHeight;
    double perpendicularDistance;


    perpendicularDistance = distance * cos(rayAngle - data->player->facing_angle);
    projPlaneDistance = (data->W_Width / 2) / tan(FOV_ANGLE / 2);
    wallHeight = (TILE_SIZE / perpendicularDistance) * projPlaneDistance;
    if (wallHeight > data->W_Height)
        wallHeight = data->W_Height;
    if (wallHeight < 0)
        wallHeight = 0;
    renderWall(data, rayId, ((data->W_Height / 2) - (wallHeight / 2)), wallHeight, 0x00FF);
}   
