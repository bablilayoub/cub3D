/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:12:20 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/01 21:37:50 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void draw_map_sqaures(t_data *data, int x, int y, int color)
{
	int i;
	int j;
    int scaleFactor;

    scaleFactor = MINIMAP_SCALE_FACTOR * TILE_SIZE;
	i = -1;
	while (++i < scaleFactor)
	{
		j = -1;
		while (++j < scaleFactor)
			*(unsigned int *)(data->addr + ((y + i) * data->line_length + (x + j) * (data->bits_per_pixel / 8)) ) = color;
	}
}

void render_map(t_data *data)
{
    int i;
    int j;
    int tileX;
    int tileY;

    i = -1;
    while (data->map[++i])
    {
        j = -1;
        while (data->map[i][++j])
        {
            tileX = j * TILE_SIZE * MINIMAP_SCALE_FACTOR;
            tileY = i * TILE_SIZE * MINIMAP_SCALE_FACTOR;
            if (data->map[i][j] == '1')
                draw_map_sqaures(data,  tileX,   tileY, 0x003F3F3F);
            else
                draw_map_sqaures(data,  tileX,   tileY, 0x00000000);
        }
    }
}

void render_player(t_data *data, int color)
{
	int playerX;
	int playerY;
	int i;
	int j;

	playerX = data->player->posX * MINIMAP_SCALE_FACTOR;
	playerY = data->player->posY * MINIMAP_SCALE_FACTOR;
	j = -1;
	while (++j < data->player->radius)
	{
		i = -1;
		while (++i < data->player->radius)
			*(unsigned int *)(data->addr + ((playerY + i) * data->line_length + (playerX + j) * (data->bits_per_pixel / 8)) ) = color;
	}
    // draw crosshair in the middle of the screen
    i = -1;
    while (++i < 3)
    {
        j = -1;
        while (++j < 3)
            *(unsigned int *)(data->addr + ((data->W_Height / 2 + i) * data->line_length + (data->W_Width / 2 + j) * (data->bits_per_pixel / 8)) ) = 0x00FF0000;
    }
}

// void line(t_data *data, int x0, int y0, int x1, int y1)
// {
//     int dx = abs(x1 - x0);
//     int dy = abs(y1 - y0);
//     int sx = (x0 < x1) ? 1 : -1;
//     int sy = (y0 < y1) ? 1 : -1;
//     int err = dx - dy;
// 	int e2;

//     while (1)
//     {
// 		if (x0 < 0 || x0 >= data->W_Width || y0 < 0 || y0 >= data->W_Height)
// 			return ;
// 		*(unsigned int *)(data->addr + (y0 * data->line_length + x0 * (data->bits_per_pixel / 8))) =  0x1439f5;
//         if (x0 == x1 && y0 == y1)
//             break;
//         e2 = err * 2;
//         if (e2 > -dy)
//         {
//             err -= dy;
//             x0 += sx;
//         }
//         if (e2 < dx)
//         {
//             err += dx;
//             y0 += sy;
//         }
//     }
// }

// void add_line_toplayer(t_data *data, double rayAngle)
// {
// 	int lineStartX;
// 	int lineStartY;
// 	int linendX = 0;
// 	int linendY = 0;

	
// 	lineStartX = (data->player->posX) + TILE_SIZE ;
// 	lineStartY = (data->player->posY) + TILE_SIZE ;
// 	linendX = lineStartX + cos(rayAngle);
// 	linendY = lineStartY + sin(rayAngle);
// }
