/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/01 12:08:21 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	mouse_move(int x, int y, t_data *data)
{
	(void)y;
	int	temp_width;

	temp_width = data->W_Width / 3;
	if (x > 2 * temp_width && x < data->W_Width)
		data->player->turn_direction = 1;
	else if (x < temp_width && x > 0)
		data->player->turn_direction = -1;
	else
		data->player->turn_direction = 0;
	return (0);
}

// int	mouse_press(int button, int x, int y, t_data *data)
// {
// 	(void)x;
// 	(void)y;
// 	(void)data;
// 	if (button == 1)
// 		mlx_mouse_hide();
// 	else if (button == 2)
// 		mlx_mouse_show();
// 	return (0);
// }

void set_up_window(t_data *data, int  W_Width, int W_Height)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, W_Width, W_Height, "cub3D");
	get_xpms(data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->win, 17, 1L << 17, (void *)exit_game_clean, data);
	mlx_hook(data->win, 6, 1L << 6, mouse_move, data);
	// mlx_mouse_hook(data->win, mouse_press, data);
	mlx_loop_hook(data->mlx, draw, data);
	mlx_loop(data->mlx);
}

void	execute(t_data *data)
{
	initialize_player(data);
	set_up_window(data, data->W_Width, data->W_Height);
}
