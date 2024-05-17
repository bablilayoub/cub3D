/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:21:59 by abablil           #+#    #+#             */
/*   Updated: 2024/05/16 20:15:02 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	look_for_map_file(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_game("Couldn't find a map with this path", 1, 1);
}

void	validate_input(char *map_path)
{
	if (!ft_strlen(map_path))
		exit_game("Map name can't be empty", 1, 1);
	if (ft_strncmp(map_path + (ft_strlen(map_path) - 4), ".cub", 4))
		exit_game("Invalid map extension", 1, 1);
	look_for_map_file(map_path);
}

int main(int total, char **args)
{
	if (total != 2)
	{
		printf("\033[30m\033[102m Usage \033[0m : ./cube3D [map path]\n");
		return (1);
	}
	validate_input(args[1]);
}