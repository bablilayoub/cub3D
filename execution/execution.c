/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/31 10:14:59 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void set_up_window(t_data *data, int  W_Width, int W_Height)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, W_Width, W_Height, "cub3D");
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->win, 17, 1L << 17, (void *)exit_game_clean, data);
	mlx_loop_hook(data->mlx, draw, data);
	mlx_loop(data->mlx);
}

void	execute(t_data *data)
{
	initialize_player(data);
	set_up_window(data, data->W_Width, data->W_Height);
}
