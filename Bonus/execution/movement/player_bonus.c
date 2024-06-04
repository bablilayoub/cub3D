/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:28:49 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/04 19:00:53 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution_bonus.h"

void	opend_door(t_data *data)
{
	int		index_x;
	int		index_y;
	int		i;
	t_doors	*head;

	i = 0;
	head = data->doors;
	index_x = floor(data->player->pos_x / TILE_SIZE);
	index_y = floor(data->player->pos_y / TILE_SIZE);
	if (check_closest_door(data, index_x, index_y))
	{
		while (data->doors)
		{
			if (check_if_compatibles(data, index_x, index_y))
				upadte_values(data);
			data->doors = data->doors->next;
		}
		data->doors = head;
	}
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESCP)
	{
		system("killall afplay");
		exit_game("Exit game", data, -1, 0);
	}
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
	else if (keycode == DOOR_OPENED)
		opend_door(data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_S)
		data->player->walk_direction = 0;
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		data->player->turn_direction = 0;
	else if (keycode == KEY_A || keycode == KEY_D)
		data->player->movement = 0;
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	int	temp_width;

	(void)y;
	temp_width = data->w_width / 3;
	if (x > 2 * temp_width && x < data->w_width)
		data->player->turn_direction = 1;
	else if (x < temp_width && x > 0)
		data->player->turn_direction = -1;
	else
		data->player->turn_direction = 0;
	return (0);
}
