/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/25 19:19:04 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void set_up_window(t_data *data, int W_Height, int  W_Width)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, W_Width, W_Height, GAME_NAME);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->win, 17, 1L << 17, (void *)exit_game, data);
	mlx_loop_hook(data->mlx, draw, data);
	mlx_loop(data->mlx);
}

void	execute(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	initialize_player(data);
	set_up_window(data, array_len(data->map) * TILE_SIZE, ft_strlen(data->map[0]) * TILE_SIZE);
}
