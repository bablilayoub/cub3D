/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:28:49 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/30 14:51:16 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	initialize_player(t_data *data)
{
	data->player->posX = data->player_x * TILE_SIZE + TILE_SIZE / 2;
	data->player->posY = data->player_y * TILE_SIZE + TILE_SIZE / 2;
	data->player->turn_direction = 0;
	data->player->walk_direction = 0;
	data->player->movement = 0;
	data->newPlayerX = 0;
	data->newPlayerY = 0;
	data->player->radius = RADIUS;
	data->player->move_speed = MOVE_SPEED;
	if (data->map[data->player_y][data->player_x] == 'N')
		data->player->rotation_angle = 3 * (M_PI / 2);
	else if (data->map[data->player_y][data->player_x] == 'S')
		data->player->rotation_angle = M_PI / 2;
	else if (data->map[data->player_y][data->player_x] == 'E')
		data->player->rotation_angle = 0;
	else if (data->map[data->player_y][data->player_x] == 'W')
		data->player->rotation_angle = M_PI;
	data->player->rotation_speed = 2 * (M_PI / 180);
}

int key_press(int keycode, t_data *data)
{
	if (keycode == ESCP)
		exit_game("Exit game", data, -1, 0);
	else if (keycode == KEY_W)
		data->player->walk_direction = 1;
	else if (keycode == KEY_S)
		data->player->walk_direction = -1;
	else if (keycode == KEY_LEFT)
		data->player->turn_direction = -1;
	else if (keycode == KEY_RIGHT)
		data->player->turn_direction = 1;
	else if (keycode == KEY_A)
		data->player->movement = -1;
	else if (keycode == KEY_D)
		data->player->movement = 1;
	return 0;
}

int key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_S)
		data->player->walk_direction = 0;
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		data->player->turn_direction = 0;
	else if (keycode == KEY_A || keycode == KEY_D)
		data->player->movement = 0;
	return 0;
}
