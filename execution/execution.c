/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/25 18:33:25 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void Set_up_Window(t_exec *data, int W_Height, int  W_Width)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, W_Height, W_Width, "Cub3d");
	mlx_hook(data->mlx_win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, (void *)exit_game, data);
	mlx_loop_hook(data->mlx, draw, data);
	mlx_loop(data->mlx);
}

int	execute(t_data *data)
{
	ft_memset(&data, 0, sizeof(data));
	initialize_player(&data);
	Set_up_Window(&data, MAP_H * TILE_SIZE, MAP_W * TILE_SIZE);
}
