/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:25:04 by abablil           #+#    #+#             */
/*   Updated: 2024/06/04 22:50:21 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_textures_path(t_data *data)
{
	int	fd;

	fd = open(data->north_texture, O_RDONLY);
	if (fd == -1)
		exit_game("Invalid north texture path.", data, -1, 1);
	close(fd);
	fd = open(data->south_texture, O_RDONLY);
	if (fd == -1)
		exit_game("Invalid south texture path.", data, -1, 1);
	close(fd);
	fd = open(data->west_texture, O_RDONLY);
	if (fd == -1)
		exit_game("Invalid west texture path.", data, -1, 1);
	close(fd);
	fd = open(data->east_texture, O_RDONLY);
	if (fd == -1)
		exit_game("Invalid east texture path.", data, -1, 1);
	close(fd);
}

void	check_textures(t_data *data)
{
	if (!data->north_texture || !data->south_texture
		|| !data->west_texture || !data->east_texture)
		exit_game("Missing textures.", data, -1, 1);
	if (!data->floor_color || !data->ceiling_color)
		exit_game("Missing colors.", data, -1, 1);
	check_textures_path(data);
	check_colors_format(data);
}

void	check_invalid_chars(t_data *data)
{
	int	i;

	i = data->start_point;
	while (data->map_file[i] && data->map_file[i] == '\n')
		i++;
	while (data->map_file[i] && data->map_file[i] != '\n')
	{
		if (!ft_strchr(" 1", data->map_file[i]))
			exit_game("Invalid map border.", data, -1, 1);
		i++;
	}
	while (data->map_file[i])
	{
		if (!ft_strchr(" 01NSEW\n", data->map_file[i]))
			exit_game("Invalid character in map.", data, -1, 1);
		i++;
	}
}
