/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:00:15 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/06 13:56:16 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

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

int	draw(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	create_image(data);
	update_player_pos(data, data->newplayerx, data->newplayery);
	castallrays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
