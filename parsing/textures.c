/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:21:43 by abablil           #+#    #+#             */
/*   Updated: 2024/05/26 10:38:10 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*get_texture(t_data *data, int *i, char *texture_data)
{
	char	*texture;
	int		j;

	if (texture_data)
		exit_game("Duplicate texture.", data, -1, 1);
	while (data->map_file[*i] && data->map_file[*i] != ' '
			&& data->map_file[*i] != '\n')
		(*i)++;
	while (data->map_file[*i] && data->map_file[*i] == ' ')
		(*i)++;
	j = 0;
	while (data->map_file[*i + j] && data->map_file[*i + j] != '\n')
		j++;
	texture = ft_substr(data->map_file, *i, j);
	if (!texture)
		return (NULL);
	if (!ft_strlen(texture))
	{
		free(texture);
		return (NULL);
	}
	*i += j;
	return (texture);
}

void	get_textures(t_data *data)
{
	int i;
	
	i = 0;
	while (data->map_file[i])
	{
		if (data->north_texture && data->south_texture
			&& data->west_texture && data->east_texture
			&& data->floor_color && data->ceiling_color)
			break ;
		if (data->map_file[i] == 'N' && data->map_file[i + 1] == 'O')
			data->north_texture = get_texture(data, &i, data->north_texture);
		else if (data->map_file[i] == 'S' && data->map_file[i + 1] == 'O')
			data->south_texture = get_texture(data, &i, data->south_texture);
		else if (data->map_file[i] == 'W' && data->map_file[i + 1] == 'E')
			data->west_texture = get_texture(data, &i, data->west_texture);
		else if (data->map_file[i] == 'E' && data->map_file[i + 1] == 'A')
			data->east_texture = get_texture(data, &i, data->east_texture);
		else if (data->map_file[i] == 'F' && data->map_file[i + 1] == ' ')
			data->floor_color = get_texture(data, &i, data->floor_color);
		else if (data->map_file[i] == 'C' && data->map_file[i + 1] == ' ')
			data->ceiling_color = get_texture(data, &i, data->ceiling_color);
		else
			i++;
	}
	data->start_point = i;
}
