/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:12:20 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/29 19:07:53 by alaalalm         ###   ########.fr       */
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

    i = -1;
    while (data->map[++i])
    {
        j = -1;
        while (data->map[i][++j])
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

    while (1)
    {
		if (x0 < 0 || x0 >= data->map_width * TILE_SIZE || y0 < 0 || y0 >= data->map_height * TILE_SIZE)
			return ;
		*(unsigned int *)(data->addr + (y0 * data->line_length + x0 * (data->bits_per_pixel / 8))) =  0x1439f5;
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
	int linendX = 0;
	int linendY = 0;

	
	lineStartX = (data->player->posX) + TILE_SIZE ;
	lineStartY = (data->player->posY) + TILE_SIZE ;
	linendX = lineStartX + cos(rayAngle);
	linendY = lineStartY + sin(rayAngle);
	line(data, lineStartX, lineStartY, linendX, linendY);
}
void render_player(t_data *data, int color)
{
	int i;
	int j;
	int x;
	int y;
	int radius = 3;

	i = -radius;
	while (++i < radius)
	{
		j = -radius;
		while (++j < radius)
		{
			if (i * i + j * j <= radius * radius)
			{
				x = data->player->posX + i;
				y = data->player->posY + j;
				*(unsigned int *)(data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8))) = color;
			}
		}
	}
}


void castAllRays(t_data *data)
{
	int		columnId;

	double rayAngle = normalize_angle(data->player->rotation_angle - (FOV_ANGLE / 2));
	columnId = -1;
	while (++columnId < data->map_width * TILE_SIZE)
	{
		castRay(data, rayAngle);
		rayAngle += FOV_ANGLE / (data->map_width * TILE_SIZE);

	}
}

void render(t_data *data)
{
	render_map(data);
	render_player(data, 0xFF0000);
}

void create_image(t_data *data)
{
	data->img = mlx_new_image(data->mlx, data->map_width * TILE_SIZE, data->map_height * TILE_SIZE);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
}
int	draw(void *param) 
{
	t_data	*data;

	data = (t_data *)param;
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	create_image(data);
	update_player_pos(data, data->newPlayerX, data->newPlayerY);
	render(data);
	castAllRays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
