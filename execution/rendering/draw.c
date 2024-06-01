/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:00:15 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/01 12:35:15 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

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

int get_pixel(t_texture *texture, int x, int y)
{
	int	color;

	color = *(int *)(texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8)));
	if (color < 0)
		return (0);
	return (color);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
	render_map(data);
	render_player(data, 0xFF0000);
	render_torch(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}