/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:00:15 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/31 19:07:22 by alaalalm         ###   ########.fr       */
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

int	draw(void *param) 
{
	t_data	*data;

	data = (t_data *)param;
	create_image(data);
	update_player_pos(data, data->newPlayerX, data->newPlayerY);
	castAllRays(data);
	render_map(data);
	render_player(data, 0x00FF);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}