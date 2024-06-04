/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:28:06 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/04 16:38:35 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	initialize_player(t_data *data)
{
	data->player->pos_x = data->player_x * TILE_SIZE + TILE_SIZE / 2;
	data->player->pos_y = data->player_y * TILE_SIZE + TILE_SIZE / 2;
	data->w_width = data->map_width * TILE_SIZE;
	data->w_height = data->map_height * TILE_SIZE;
	data->player->radius = RADIUS;
	data->player->speed = MOVE_SPEED;
	data->player->turn_direction = 0;
	data->player->walk_direction = 0;
	data->player->movement = 0;
	data->newplayerx = 0;
	data->newplayery = 0;
	if (data->map[data->player_y][data->player_x] == 'N')
		data->player->angle = M_PI + M_PI_2;
	else if (data->map[data->player_y][data->player_x] == 'S')
		data->player->angle = M_PI_2;
	else if (data->map[data->player_y][data->player_x] == 'E')
		data->player->angle = 0;
	else if (data->map[data->player_y][data->player_x] == 'W')
		data->player->angle = M_PI;
	data->player->rotation_speed = 4 * (M_PI / 180);
}

void	set_up_window(t_data *data, int w_width, int w_height)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_game("Failed to initialize mlx", data, -1, 1);
	data->win = mlx_new_window(data->mlx, w_width, w_height, "cub3D");
	if (!data->win)
		exit_game("Failed to create window", data, -1, 1);
	get_xpms(data);
	if (access("./sounds/background.mp3", F_OK) != -1)
		system("afplay ./sounds/background.mp3 &");
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 3, 0, key_release, data);
	mlx_hook(data->win, 17, 0, (void *)exit_game_clean, data);
	mlx_hook(data->win, 6, 0, mouse_move, data);
	mlx_loop_hook(data->mlx, draw, data);
	mlx_loop(data->mlx);
}

void	execute(t_data *data)
{
	initialize_player(data);
	set_up_window(data, data->w_width, data->w_height);
}
