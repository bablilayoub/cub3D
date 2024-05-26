/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:28:49 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/26 10:41:40 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	initialize_player(t_data *data)
{
	data->player->posX = ft_strlen(data->map[1]) - 1;
	data->player->posY = 2;
	data->player->radius = 3;
	data->player->turn_direction = 0;
	data->player->walk_direction = 0;
	data->player->movement = 0;
	data->player->rotation_angle = M_PI / 2;
	data->player->move_speed = 0.06;
	data->player->rotation_speed = 6 * (M_PI / 180);
}

int key_press(int keycode, t_data *data)
{
	if (keycode == ESCP)
		exit_game("Exit game", data, -1);
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
