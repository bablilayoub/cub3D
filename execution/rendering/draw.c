/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:00:15 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/02 15:14:19 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int get_pixel(t_texture *texture, int x, int y)
{
	int	color;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	color = *(int *)(texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8)));
	if (color < 0)
		return (0);
	return (color);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= data->W_Width || y < 0 || y >= data->W_Height)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


int get_texture_color(t_data *data, int textureOffsetX, int textureOffsetY, double rayAngle)
{
	(void)rayAngle;
	int		color;
	
	color = 0;
	color = get_pixel(data->north_texture_struct, textureOffsetX * data->north_texture_struct->width / TILE_SIZE, textureOffsetY * data->north_texture_struct->height / TILE_SIZE);
	return (color);
}

void render_column(t_data *data, int rayId, double rayAngle, double distance)
{
	int		wallStripHeight;
	int		wallTopPixel;
	int		wallBottomPixel;
	int		textureOffsetX;
	int		textureOffsetY;
	int		textureColor;
	int		i;
	int		distance_proj_plane;

	distance_proj_plane = (data->W_Width / 2) / tan(FOV_ANGLE / 2);
	wallStripHeight = (TILE_SIZE / distance) * distance_proj_plane;
	wallTopPixel = (data->W_Height / 2) - (wallStripHeight / 2);
	wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;
	wallBottomPixel = (data->W_Height / 2) + (wallStripHeight / 2);
	wallBottomPixel = wallBottomPixel > data->W_Height ? data->W_Height : wallBottomPixel;
	textureOffsetX = (int)data->rays->wallHitX % TILE_SIZE;
	textureOffsetY = (int)data->rays->wallHitY % TILE_SIZE;
	// check if wall is facing up or down
	if (data->rays->wasHitVertical)
		textureOffsetX = (int)data->rays->wallHitY % TILE_SIZE;
	else
		textureOffsetX = (int)data->rays->wallHitX % TILE_SIZE;
	// check if wall height is bigger or equal to the screen height
	if (wallStripHeight >= data->W_Height)
		wallTopPixel -= (wallStripHeight - data->W_Height) / 2;
	i = -1;
	while (++i < data->W_Height)
	{
		if (i < wallTopPixel)
			my_mlx_pixel_put(data, rayId, i, 0x000000);
		else if (i > wallTopPixel && i < wallBottomPixel)
		{
			textureOffsetY = (int)(i - wallTopPixel) * ((float)TILE_SIZE / wallStripHeight);
			if (data->map[(int)data->rays->wallHitY / TILE_SIZE][(int)data->rays->wallHitX / TILE_SIZE] == 'D')
				textureColor = 0x00FF00;
			else
				textureColor = get_texture_color(data, textureOffsetX, textureOffsetY, rayAngle);
			my_mlx_pixel_put(data, rayId, i, textureColor);
		}
		else
			my_mlx_pixel_put(data, rayId, i, 0x000000);
	}
}

void castAllRays(t_data *data)
{
	int		rayId;

	double rayAngle = normalize_angle(data->player->facing_angle - (FOV_ANGLE / 2));
	rayId = -1;
	while (++rayId < data->W_Width)
	{
		castRay(data, rayAngle);
		render_column(data, rayId, rayAngle, data->rays->distance);
		rayAngle += FOV_ANGLE / data->W_Width;
	}
}

void create_image(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->W_Width, data->W_Height);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
}

void render_torch(t_data *data)
{
	int		torch_width;
	int		torch_height;
	int		middle_x;
	int		bottom_y;
	int		x;
	int		y;
	int		color;

	torch_width = data->torch_1_texture->width;
	torch_height = data->torch_1_texture->height;
	middle_x = data->W_Width / 1.4 - torch_width / 2;
	bottom_y = data->W_Height - torch_height;
	x = -1;
	if (data->flag >= 80)
		data->flag = 1;
	while (++x < torch_width)
	{
		y = -1;
		while (++y < torch_height)
		{
			if (data->flag >= 1 && data->flag <= 9)
				color = get_pixel(data->torch_1_texture, x, y);
			else if (data->flag >= 10 && data->flag <= 19)
				color = get_pixel(data->torch_2_texture, x, y);
			else if (data->flag >= 20 && data->flag <= 29)
				color = get_pixel(data->torch_3_texture, x, y);
			else if (data->flag >= 30 && data->flag <= 39)
				color = get_pixel(data->torch_4_texture, x, y);
			else if (data->flag >= 40 && data->flag <= 49)
				color = get_pixel(data->torch_5_texture, x, y);
			else if (data->flag >= 50 && data->flag <= 59)
				color = get_pixel(data->torch_6_texture, x, y);
			else if (data->flag >= 60 && data->flag <= 69)
				color = get_pixel(data->torch_7_texture, x, y);
			else if (data->flag >= 70 && data->flag <= 79)
				color = get_pixel(data->torch_8_texture, x, y);
			if (color != 0)
				my_mlx_pixel_put(data, middle_x + x, bottom_y + y, color);
		}
	}
	data->flag++;
}


int	draw(void *param) 
{
	t_data	*data;

	data = (t_data *)param;
	create_image(data);
	update_player_pos(data, data->newPlayerX, data->newPlayerY);
	castAllRays(data);
	render_torch(data);
	render_map(data);
	render_player(data, 0xFF0000);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}