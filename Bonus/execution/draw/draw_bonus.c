/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:00:15 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/06 21:25:46 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution_bonus.h"

void	castallrays(t_data *data)
{
	int		ray_id;
	double	ray_angle;

	ray_angle = normalize_angle(data->player->angle - (FOV_ANGLE / 2));
	ray_id = -1;
	while (++ray_id < S_WIDTH)
	{
		castray(data, ray_angle);
		render_column(data, ray_id, data->rays->distance, ray_angle);
		ray_angle += FOV_ANGLE / S_WIDTH;
	}
}

void	draw_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->w_width / 2 - data->ghost_texture->width / 2)
	{
		j = 0;
		while (j < data->w_height)
		{
			my_mlx_pixel_put(data, i, j, 0x000000);
			j++;
		}
		i++;
	}
	i = data->w_width / 2 + data->ghost_texture->width / 2;
	while (i < data->w_width)
	{
		j = 0;
		while (j < data->w_height)
		{
			my_mlx_pixel_put(data, i, j, 0x000000);
			j++;
		}
		i++;
	}
}

void	draw_ghost(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	color;

	x = S_WIDTH / 2 - data->ghost_texture->width / 2;
	y = S_HEIGHT / 2 - data->ghost_texture->height / 2;
	i = 0;
	while (i < data->ghost_texture->width)
	{
		j = 0;
		while (j < data->ghost_texture->height)
		{
			color = *(int *)(data->ghost_texture->addr
					+ (j * data->ghost_texture->line_length + i
						* (data->ghost_texture->bits_per_pixel / 8)));
			if (color != 0)
				my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
	draw_background(data);
}

void	random_jumpscare(t_data *data)
{
	int		rand_num;

	rand_num = rand() % 1000;
	if (rand_num == 1)
	{
		if (access("./sounds/jump_scare.mp3", F_OK) != -1)
			system("afplay ./sounds/jump_scare.mp3 &");
		draw_ghost(data);
		data->jumpscare = 1;
	}
	else if (data->jumpscare == 1 && data->jumpscare_timer < 15)
	{
		draw_ghost(data);
		data->jumpscare_timer++;
	}
	if (data->jumpscare_timer == 15)
	{
		data->jumpscare = 0;
		data->jumpscare_timer = 0;
	}
}

int	draw(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	create_image(data);
	update_player_pos(data, data->newplayerx, data->newplayery);
	castallrays(data);
	render_torch(data);
	render_map(data);
	random_jumpscare(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
