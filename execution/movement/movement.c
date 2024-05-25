/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:04:48 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/25 18:37:01 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int player_movment(t_exec *data, double newPlayerX, double newPlayerY)
{
	double newX;
	double newY;
	int indexX;
	int indexY;

	newX = data->player.posX + newPlayerX;
	newY = data->player.posY + newPlayerY;
	indexX = floor(newX);
	indexY = floor(newY);
	if (indexX < 0 || indexX >= MAP_W || indexY < 0 || indexY >= MAP_H)
		return (1);
	if (data->Map[indexY][indexX] != '1')
	{
		data->player.posX = newX;
		data->player.posY = newY;
	}
	return (0);
}

int Update_Player_Pos(t_exec *data, double newPlayerX, double newPlayerY)
{
	if (data->player.turn_direction == 1)
		data->player.rotation_angle += data->player.rotation_speed;
	else if (data->player.turn_direction == -1)
		data->player.rotation_angle -= data->player.rotation_speed;
	if (data->player.movement == 1)
	{
		newPlayerX = -sin(data->player.rotation_angle) * data->player.move_speed;
		newPlayerY = cos(data->player.rotation_angle) * data->player.move_speed;
	}
	else if (data->player.movement == -1)
	{
		newPlayerX = sin(data->player.rotation_angle) * data->player.move_speed;
		newPlayerY = -cos(data->player.rotation_angle) * data->player.move_speed;
	}
	if (data->player.walk_direction == 1)
	{
		newPlayerX = cos(data->player.rotation_angle) * data->player.move_speed;
		newPlayerY = sin(data->player.rotation_angle) * data->player.move_speed;
	}
	else if (data->player.walk_direction == -1)
	{
		newPlayerX = -cos(data->player.rotation_angle) * data->player.move_speed;
		newPlayerY = -sin(data->player.rotation_angle) * data->player.move_speed;
	}
	player_movment(data, newPlayerX, newPlayerY);
	return (0);
}