/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:04:48 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/06 14:09:46 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int	check_dioagonal_collision(t_data *data, int indexX, int indexY)
{
	int	curr_x;
	int	curr_y;

	curr_x = floor(data->player->pos_x / TILE_SIZE);
	curr_y = floor(data->player->pos_y / TILE_SIZE);
	if (indexX != curr_x && indexY != curr_y)
	{
		if (data->map[curr_y][indexX] == '1'
			|| data->map[indexY][curr_x] == '1')
			return (1);
	}
	return (0);
}

int	player_movment(t_data *data, double newPlayerX, double newPlayerY)
{
	double	new_x;
	double	new_y;
	int		index_x;
	int		index_y;

	if (newPlayerX == 0 && newPlayerY == 0)
		return (1);
	new_x = data->player->pos_x + newPlayerX;
	new_y = data->player->pos_y + newPlayerY;
	index_x = floor(new_x / TILE_SIZE);
	index_y = floor(new_y / TILE_SIZE);
	if (index_x < 0 || index_x >= S_WIDTH
		|| index_y < 0 || index_y >= S_HEIGHT)
		return (1);
	if (data->map[index_y][index_x] == '1')
		return (1);
	if (check_dioagonal_collision(data, index_x, index_y))
		return (1);
	data->player->pos_x = new_x;
	data->player->pos_y = new_y;
	return (0);
}

void	update_player_pos(t_data *data, double newPlayerX, double newPlayerY)
{
	if (data->player->turn_direction == 1)
		data->player->angle += data->player->rotation_speed;
	else if (data->player->turn_direction == -1)
		data->player->angle -= data->player->rotation_speed;
	if (data->player->walk_direction == 1)
	{
		newPlayerX = cos(data->player->angle) * data->player->speed;
		newPlayerY = sin(data->player->angle) * data->player->speed;
	}
	else if (data->player->walk_direction == -1)
	{
		newPlayerX = -cos(data->player->angle) * data->player->speed;
		newPlayerY = -sin(data->player->angle) * data->player->speed;
	}
	if (data->player->movement == 1)
	{
		newPlayerX = -sin(data->player->angle) * data->player->speed;
		newPlayerY = cos(data->player->angle) * data->player->speed;
	}
	else if (data->player->movement == -1)
	{
		newPlayerX = sin(data->player->angle) * data->player->speed;
		newPlayerY = -cos(data->player->angle) * data->player->speed;
	}
	player_movment(data, newPlayerX, newPlayerY);
}
