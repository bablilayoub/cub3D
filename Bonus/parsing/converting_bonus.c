/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:23:24 by abablil           #+#    #+#             */
/*   Updated: 2024/06/04 20:29:48 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

char	*expand_line(char *line, size_t size)
{
	char	*new_line;
	size_t	i;

	new_line = malloc(sizeof(char) * (size + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	while (i < size)
	{
		new_line[i] = ' ';
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

void	convert_tabs(t_data *data)
{
	char	*new_map;
	int		i;
	int		j;

	(1) && (i = -1, j = 0);
	new_map = ft_calloc(ft_strlen(data->map_file) * 2 + 1, sizeof(char *));
	if (!new_map)
		exit_game("Failed to allocate temp_map.", data, -1, 1);
	while (data->map_file[++i])
	{
		if (data->map_file[i] == '\t')
		{
			new_map[j++] = ' ';
			new_map[j++] = ' ';
			new_map[j++] = ' ';
			new_map[j++] = ' ';
		}
		else
			new_map[j++] = data->map_file[i];
	}
	new_map[j] = '\0';
	free(data->map_file);
	data->map_file = new_map;
}

int	get_biggest_line(char **map)
{
	int	i;
	int	j;
	int	biggest;

	i = 0;
	j = 0;
	biggest = 0;
	while (map[i])
	{
		while (map[i][j])
			j++;
		if (j > biggest)
			biggest = j;
		j = 0;
		i++;
	}
	return (biggest);
}
