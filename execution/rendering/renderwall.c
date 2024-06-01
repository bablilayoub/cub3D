/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderwall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:06:33 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/01 21:10:54 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

// void renderCeiling(t_data *data, int rayId, int y, int color)
// {
//     int i;
//     int j;

//     i = -1;
//     while (++i < y)
//     {
//         j = -1;
//         while (++j < 1)
//             *(unsigned int *)(data->addr + ((i) * data->line_length + (rayId) * (data->bits_per_pixel / 8)) ) = color;
//     }
// }

// void renderFloor(t_data *data, int rayId, int y, int color)
// {
//     int i;
//     int j;

//     i = -1;
//     while (++i < data->W_Height - y)
//     {
//         j = -1;
//         while (++j < 1)
//             *(unsigned int *)(data->addr + ((y + i) * data->line_length + (rayId) * (data->bits_per_pixel / 8)) ) = color;
//     }
// }
// void renderWall(t_data *data, int rayId, int y, int wallHeight, int color)
// {
//     int i;
//     int j;
//     color = 0xFF0000;
//     i = -1w;
//     while (++i < wallHeight)
//     {
//         j = -1;
//         while (++j < 1)
//         {
//             *(unsigned int *)(data->addr + ((y + i) * data->line_length + (rayId) * (data->bits_per_pixel / 8)) ) = color;
//             color = color - 0x000101;
//         }
//     }
// }
// void render_column(t_data *data, int rayId, double rayAngle, double distance)
// {
// 	double projPlaneDistance;
// 	int wallHeight;
//     double perpendicularDistance;
//     int color;


//     perpendicularDistance = distance * cos(rayAngle - data->player->facing_angle);
//     projPlaneDistance = (data->W_Width / 2) / tan(FOV_ANGLE / 2);
//     wallHeight = (TILE_SIZE / perpendicularDistance) * projPlaneDistance;
//     if (wallHeight > data->W_Height)
//         wallHeight = data->W_Height;
//     if (wallHeight < 0)
//         wallHeight = 0;
//     if (data->rays->wasHitVertical)
//         color = 0xa8a0a0;
//     else
//         color = 0xf5ebeb;
//     renderWall(data, rayId, (data->W_Height / 2) - (wallHeight / 2), wallHeight, color);
//     renderCeiling(data, rayId, (data->W_Height / 2) - (wallHeight / 2), 0x000000);
//     renderFloor(data, rayId, (data->W_Height / 2) + (wallHeight / 2), 0x000000);
// }   
