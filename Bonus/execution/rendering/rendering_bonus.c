/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:12:20 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/06 20:03:35 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution_bonus.h"

void	draw_map_sqaures(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	scalefactor;

	scalefactor = MINIMAP_SCALE_FACTOR * TILE_SIZE;
	i = -1;
	while (++i < scalefactor)
	{
		j = -1;
		while (++j < scalefactor)
			*(unsigned int *)(data->addr + ((y + i) * data->line_length
						+ (x + j) * (data->bits_per_pixel / 8))) = color;
	}
}


void	render_map(t_data *data)
{
	int	player_x;
	int	player_y;
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	x;
	int	y;
	int	color;

	player_x = data->player->pos_x / TILE_SIZE;
	player_y = data->player->pos_y / TILE_SIZE;

	start_x = (player_x > 10) ? player_x - 10 : 0;
	start_y = (player_y > 10) ? player_y - 10 : 0;
	end_x = (player_x + 10 < data->map_width) ? player_x + 10 : data->map_width - 1;
	end_y = (player_y + 10 < data->map_height) ? player_y + 10 : data->map_height - 1;

	for (y = start_y; y <= end_y; y++)
	{
		for (x = start_x; x <= end_x; x++)
		{
			if (x >= (int)ft_strlen(data->map[y]))
				break;
			if (x == player_x && y == player_y)
				color = 0xa817e6;
			else if (data->map[y][x] == '1')
				color = 0x00FFFFFF;
			else if (data->map[y][x] == '0')
				color = 0x00000000;
			else if (data->map[y][x] == 'D')
				color = 0xe6173d;
			else
				color = 0x00000000;
			draw_map_sqaures(data, (x - player_x + 10) * MINIMAP_SCALE_FACTOR * 35,
				(y - player_y + 10) * MINIMAP_SCALE_FACTOR * 35, color);
		}
	}
}

