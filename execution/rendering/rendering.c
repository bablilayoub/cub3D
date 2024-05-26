/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:12:20 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/26 15:13:50 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"


void draw_map_sqaures(t_data *data, int x, int y, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < TILE_SIZE - 1)
	{
		j = -1;
		while (++j < TILE_SIZE - 1)
			*(unsigned int *)(data->addr + ((y + i) * data->line_length + (x + j) * (data->bits_per_pixel / 8)) ) = color;
		*(unsigned int *)(data->addr + ((y + i) * data->line_length + (x + TILE_SIZE - 1) * (data->bits_per_pixel / 8)) ) = 0x00000000;
	}
	i = -1;
	while (++i < TILE_SIZE - 1)
		*(unsigned int *)(data->addr + ((y + TILE_SIZE - 1) * data->line_length + (x + i) * (data->bits_per_pixel / 8)) ) = 0x00000000;
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
}

void line(t_data *data, int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
	int e2;


	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
    while (1)
    {
		*(unsigned int *)(data->addr + (y0 * data->line_length + x0 * (data->bits_per_pixel / 8))) = 0x00FF0000;
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

void add_line_toplayer(t_data *data, double rayAngle)
{
	int lineStartX;
	int lineStartY;
	int linendX;
	int linendY;
	
	lineStartX = data->player->posX * TILE_SIZE + 2;
	lineStartY = data->player->posY * TILE_SIZE + 2;
	linendX = lineStartX + cos(rayAngle) * 30;
	linendY = lineStartY + sin(rayAngle) * 30;
	line(data, lineStartX, lineStartY, linendX, linendY);
}
void render_player(t_data *data, int color)
{
	int x;
	int y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			*(unsigned int *)(data->addr + ((int)((data->player->posY * TILE_SIZE) + y) * data->line_length) + ((int)(data->player->posX * TILE_SIZE + x) * (data->bits_per_pixel / 8))) = color;
	}
}



void cast_AllRays(t_data *data)
{
	double rayAngle;
	int		i;

	
	rayAngle = data->player->rotation_angle - (FOV_ANGLE / 2);
	i = -1;
	while (++i <( data->map_width * TILE_SIZE))
	{
		add_line_toplayer(data, rayAngle);
		rayAngle += FOV_ANGLE / (data->map_width * TILE_SIZE);
	}
	
}
void update_all(t_data *data)
{
	double	newPlayerX;
	double	newPlayerY;

	newPlayerX = 0;
	newPlayerY = 0;
	update_player_pos(data, newPlayerX, newPlayerY);
	// cast_AllRays(data);
}
int	draw(void *param) 
{
	t_data	*data;

	data = (t_data *)param;
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	update_all(data);
	render_map(data);
	render_player(data, 0xFF0000);
	cast_AllRays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
