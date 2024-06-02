/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:09:25 by abablil           #+#    #+#             */
/*   Updated: 2024/06/02 16:34:59 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

int	*create_rgb(int r, int g, int b)
{
	int	*rgb;

	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
		return (NULL);
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
	return (rgb);
}

void	set_colors(t_data *data)
{
	char	**rgb;

	rgb = ft_split(data->floor_color, ',');
	data->floor_color_rgb = create_rgb(ft_atoi(rgb[0]),
			ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_array(rgb);
	rgb = ft_split(data->ceiling_color, ',');
	data->ceiling_color_rgb = create_rgb(ft_atoi(rgb[0]),
			ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_array(rgb);
}

void	check_colors_format(t_data *data)
{
	if (!ft_strchr(data->floor_color, ',')
		|| count_commas(data->floor_color) != 2)
		exit_game("Invalid floor color format.", data, -1, 1);
	if (!ft_strchr(data->ceiling_color, ',')
		|| count_commas(data->ceiling_color) != 2)
		exit_game("Invalid ceiling color format.", data, -1, 1);
	check_rgb(data->floor_color, data);
	check_rgb(data->ceiling_color, data);
	set_colors(data);
}
