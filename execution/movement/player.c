/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:28:49 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/01 11:41:32 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	initialize_player(t_data *data)
{
	data->player->posX = data->player_x * TILE_SIZE + TILE_SIZE / 2;
	data->player->posY = data->player_y * TILE_SIZE + TILE_SIZE / 2;
	data->W_Width = data->map_width * TILE_SIZE;
	data->W_Height = data->map_height * TILE_SIZE;
	data->player->radius = RADIUS;
	data->player->move_speed = MOVE_SPEED;
	data->player->turn_direction = 0;
	data->player->walk_direction = 0;
	data->player->movement = 0;
	data->newPlayerX = 0;
	data->newPlayerY = 0;
	if (data->map[data->player_y][data->player_x] == 'N')
		data->player->facing_angle = M_PI + M_PI_2;
	else if (data->map[data->player_y][data->player_x] == 'S')
		data->player->facing_angle = M_PI_2;
	else if (data->map[data->player_y][data->player_x] == 'E')
		data->player->facing_angle = 0;
	else if (data->map[data->player_y][data->player_x] == 'W')
		data->player->facing_angle = M_PI;
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
