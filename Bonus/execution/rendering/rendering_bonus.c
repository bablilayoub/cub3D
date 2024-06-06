/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:12:20 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/06 20:35:59 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution_bonus.h"

void	draw_map_sqaures(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	scalefactor;

	scalefactor = MINIMAP_SCALE * TILE_SIZE;
	i = -1;
	while (++i < scalefactor)
	{
		j = -1;
		while (++j < scalefactor)
			*(unsigned int *)(data->addr + ((y + i) * data->line_length
						+ (x + j) * (data->bits_per_pixel / 8))) = color;
	}
}

void	loop(t_data *data)
{
	int	x;
	int	y;

	y = data->start_y - 1;
	while (++y <= data->end_y)
	{
		x = data->start_x - 1;
		while (++x <= data->end_x)
		{
			if (x >= (int)ft_strlen(data->map[y]))
				break ;
			if (x == data->pl_x && y == data->pl_y)
				data->color = 0xa817e6;
			else if (data->map[y][x] == '1')
				data->color = 0x00FFFFFF;
			else if (data->map[y][x] == '0')
				data->color = 0x00000000;
			else if (data->map[y][x] == 'D')
				data->color = 0xe6173d;
			else
				data->color = 0x00000000;
			draw_map_sqaures(data, (x - data->pl_x + 10) * MINIMAP_SCALE * 35,
				(y - data->pl_y + 10) * MINIMAP_SCALE * 35, data->color);
		}
	}
}

void	render_map(t_data *data)
{
	data->pl_x = data->player->pos_x / TILE_SIZE;
	data->pl_y = data->player->pos_y / TILE_SIZE;
	if (data->pl_x > 10)
		data->start_x = data->pl_x - 10;
	else
		data->start_x = 0;
	if (data->pl_y > 10)
		data->start_y = data->pl_y - 10;
	else
		data->start_y = 0;
	if (data->pl_x + 10 < data->map_width)
		data->end_x = data->pl_x + 10;
	else
		data->end_x = data->map_width - 1;
	if (data->pl_y + 10 < data->map_height)
		data->end_y = data->pl_y + 10;
	else
		data->end_y = data->map_height - 1;
	loop(data);
}
