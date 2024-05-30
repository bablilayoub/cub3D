/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:00:15 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/30 15:00:23 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

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