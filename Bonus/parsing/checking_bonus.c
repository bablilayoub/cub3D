/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:25:04 by abablil           #+#    #+#             */
/*   Updated: 2024/06/06 13:48:53 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

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
	if (ft_strlen(data->north_texture) < 4
		|| ft_strlen(data->south_texture) < 4
		|| ft_strlen(data->west_texture) < 4
		|| ft_strlen(data->east_texture) < 4)
		exit_game("Invalid texture path.", data, -1, 1);
	if (ft_strncmp(data->north_texture + ft_strlen(data->north_texture) - 4,
			".xpm", 4) || ft_strncmp(data->south_texture
			+ ft_strlen(data->south_texture) - 4, ".xpm", 4)
		|| ft_strncmp(data->west_texture + ft_strlen(data->west_texture) - 4,
			".xpm", 4) || ft_strncmp(data->east_texture
			+ ft_strlen(data->east_texture) - 4, ".xpm", 4))
		exit_game("Invalid texture format.", data, -1, 1);
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
		if (!ft_strchr(" 01NSEWD\n", data->map_file[i]))
			exit_game("Invalid character in map.", data, -1, 1);
		i++;
	}
}
