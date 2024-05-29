/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:04:48 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/29 12:54:52 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int checkDioagonal_Collision(t_data *data, int indexX, int indexY)
{
	int currX;
	int currY;

	currX = floor(data->player->posX / TILE_SIZE);
	currY = floor(data->player->posY / TILE_SIZE);

	if (indexX != currX && indexY != currY) {
        if (data->map[currY][indexX] == '1' || data->map[indexY][currX] == '1')
            return 1;
    }
	return 0;
}
int player_movment(t_data *data, double newPlayerX, double newPlayerY)
{
	double newX;
	double newY;
	int indexX;
	int indexY;

	if (newPlayerX == 0 && newPlayerY == 0)
		return (1);
	newX = data->player->posX + newPlayerX;
	newY = data->player->posY + newPlayerY;
	indexX = floor(newX / TILE_SIZE);
	indexY = floor(newY / TILE_SIZE);
	if (indexX < 0 || indexX >= data->map_width * TILE_SIZE || indexY < 0 || indexY >= data->map_height * TILE_SIZE)
		return (1);
	if (data->map[indexY][indexX] == '1')
		return (1);
	if (checkDioagonal_Collision(data, indexX, indexY))
		return (1);
	data->player->posX = newX;
	data->player->posY = newY;
	return (0);
}

int update_player_pos(t_data *data, double newPlayerX, double newPlayerY)
{
	if (data->player->turn_direction == 1)
		data->player->rotation_angle += data->player->rotation_speed;
	else if (data->player->turn_direction == -1)
		data->player->rotation_angle -= data->player->rotation_speed;
	if (data->player->walk_direction == 1)
	{
		newPlayerX = cos(data->player->rotation_angle) * data->player->move_speed;
		newPlayerY = sin(data->player->rotation_angle) * data->player->move_speed;
	}
	else if (data->player->walk_direction == -1)
	{
		newPlayerX = -cos(data->player->rotation_angle) * data->player->move_speed;
		newPlayerY = -sin(data->player->rotation_angle) * data->player->move_speed;
	}
	if (data->player->movement == 1)
	{
		newPlayerX = -sin(data->player->rotation_angle) * data->player->move_speed;
		newPlayerY = cos(data->player->rotation_angle) * data->player->move_speed;
	}
	else if (data->player->movement == -1)
	{
		newPlayerX = sin(data->player->rotation_angle) * data->player->move_speed;
		newPlayerY = -cos(data->player->rotation_angle) * data->player->move_speed;
	}
	player_movment(data, newPlayerX, newPlayerY);
	return (0);
}

