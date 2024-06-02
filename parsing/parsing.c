/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:18:55 by abablil           #+#    #+#             */
/*   Updated: 2024/06/02 15:32:59 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parsing(char *map_path, t_data *data)
{
	if (!map_path || !ft_strlen(map_path))
		exit_game("Map name can't be empty.", data, -1, 1);
	if (ft_strncmp(map_path + (ft_strlen(map_path) - 4), ".cub", 4))
		exit_game("Invalid map extension.", data, -1, 1);
	get_file_data(map_path, data);
	check_duplicated_keys(data);
	check_first_six_lines(data);
	get_textures(data);
	check_invalid_chars(data);
	check_textures(data);
	get_map(data);
	is_empty_map(data);
	check_map(data);
	polish_map(data);
}