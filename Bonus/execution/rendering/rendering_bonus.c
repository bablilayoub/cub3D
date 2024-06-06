/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:12:20 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/06 16:38:17 by alaalalm         ###   ########.fr       */
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
	int	i;
	int	j;
	int	tile_x;
	int	tile_y;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			tile_x = j * TILE_SIZE * MINIMAP_SCALE_FACTOR;
			tile_y = i * TILE_SIZE * MINIMAP_SCALE_FACTOR;
			if (data->map[i][j] == '1')
				draw_map_sqaures(data, tile_x, tile_y, 0x003F3F3F);
			else if (data->map[i][j] == 'D')
				draw_map_sqaures(data, tile_x, tile_y, 0x2565fa);
			else
				draw_map_sqaures(data, tile_x, tile_y, 0x00000000);
		}
	}
}

void	render_player(t_data *data, int color)
{
	int	player_x;
	int	player_y;
	int	i;
	int	j;

	player_x = data->player->pos_x * MINIMAP_SCALE_FACTOR;
	player_y = data->player->pos_y * MINIMAP_SCALE_FACTOR;
	j = -1;
	while (++j < data->player->radius)
	{
		i = -1;
		while (++i < data->player->radius)
			*(unsigned int *)(data->addr + ((player_y + i) * data->line_length
						+ (player_x + j) * (data->bits_per_pixel / 8))) = color;
	}
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			*(unsigned int *)(data->addr + ((data->w_height / 2 + i)
						* data->line_length + (data->w_width / 2 + j)
						* (data->bits_per_pixel / 8))) = 0x00FF0000;
	}
}
