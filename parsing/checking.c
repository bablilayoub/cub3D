/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:25:04 by abablil           #+#    #+#             */
/*   Updated: 2024/05/26 10:37:12 by abablil          ###   ########.fr       */
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

void	check_rgb(char *color, t_data *data)
{
	char	**rgb;
	
	rgb = ft_split(color, ',');
	if (!rgb)
		exit_game("Failed to split color.", data, -1, 1);
	if (array_len(rgb) != 3)
	{
		free_array(rgb);
		exit_game("Invalid color format.", data, -1, 1);
	}
	if (!is_number(rgb[0]) || !is_number(rgb[1]) || !is_number(rgb[2]))
	{
		free_array(rgb);
		exit_game("Invalid color format.", data, -1, 1);
	}
	if (ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255
		|| ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255
		|| ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255)
	{
		free_array(rgb);
		exit_game("Invalid color format.", data, -1, 1);
	}
	free_array(rgb);
}

void	check_colors_format(t_data *data)
{
	if (!ft_strchr(data->floor_color, ',') || count_commas(data->floor_color) != 2)
		exit_game("Invalid floor color format.", data, -1, 1);
	if (!ft_strchr(data->ceiling_color, ',') || count_commas(data->ceiling_color) != 2)
		exit_game("Invalid ceiling color format.", data, -1, 1);
	check_rgb(data->floor_color, data);
	check_rgb(data->ceiling_color, data);
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
