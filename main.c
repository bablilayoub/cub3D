/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:21:59 by abablil           #+#    #+#             */
/*   Updated: 2024/06/01 10:50:26 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int total, char **args)
{
	t_data	data;

	if (total != 2)
	{
		printf("\033[30m\033[102m Usage \033[0m : ./cub3D [map path]\n");
		return (1);
	}
	ft_memset(&data, 0, sizeof(t_data));
	parsing(args[1], &data);
	data.player = malloc(sizeof(t_player));
	if (!data.player)
		exit_game("Failed to allocate memory for player.", &data, -1, 1);
	data.rays = malloc(sizeof(t_ray) * data.map_width * TILE_SIZE);
	if (!data.rays)
		exit_game("Failed to allocate memory for rays.", &data, -1, 1);
	data.flag = 1;
	execute(&data);
	free_data(&data);
}
