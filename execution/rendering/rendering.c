/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:12:20 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/26 10:54:18 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"


void draw_map_sqaures(t_data *data, int x, int y, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < TILE_SIZE)
	{
		j = -1;
		while (++j < TILE_SIZE)
			*(unsigned int *)(data->addr + ((y + i) * data->line_length + (x + j) * (data->bits_per_pixel / 8)) ) = color;
	}
}

void render_map(t_data *data)
{
	int i;
	int j;
	int tileX;
	int tileY;

	data->img = mlx_new_image(data->mlx, data->map_width * TILE_SIZE, data->map_height * TILE_SIZE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			tileX = j * TILE_SIZE;
			tileY = i * TILE_SIZE;
			if (data->map[i][j] == '1')
				draw_map_sqaures(data, tileX, tileY, 0x00FFFFFF);
			else
				draw_map_sqaures(data, tileX, tileY, 0x00000000);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void line(void *mlx, void *win, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
	 int e2;

    while (1)
    {
        mlx_pixel_put(mlx, win, x0, y0, color);

        if (x0 == x1 && y0 == y1)
            break;
        e2 = err * 2;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}
void render_player(t_data *data, int color)
{
	int x;
	int y;
	int line_start_x;
	int line_start_y;
	int line_end_x;
	int line_end_y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			mlx_pixel_put(data->mlx, data->win, data->player->posX * TILE_SIZE + x, data->player->posY * TILE_SIZE + y, color);
		line_start_x = data->player->posX * TILE_SIZE + 2; // Center of the 8x8 square
    	line_start_y = data->player->posY * TILE_SIZE + 2; // Center of the 8x8 square
    	line_end_x = line_start_x + cos(data->player->rotation_angle) * 30;
    	line_end_y = line_start_y + sin(data->player->rotation_angle) * 30;
    	line(data->mlx, data->win, line_start_x, line_start_y, line_end_x, line_end_y, 0x00FF0000);
	}
}

int	draw(void *param) 
{
	t_data	*data;
	
	data = (t_data *)param;
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	update(data);
	render_map(data);
	// render_rays(data);
	render_player(data, 0x00FF0000);
	return (0);
}
