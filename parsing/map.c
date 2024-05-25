/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:20:51 by abablil           #+#    #+#             */
/*   Updated: 2024/05/25 11:54:19 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	map_start(t_data *data)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (data->map_file[i])
	{
		if (!ft_strncmp(data->map_file + i, "NO ", 3)
			|| !ft_strncmp(data->map_file + i, "SO ", 3)
			|| !ft_strncmp(data->map_file + i, "WE ", 3)
			|| !ft_strncmp(data->map_file + i, "EA ", 3)
			|| !ft_strncmp(data->map_file + i, "F ", 2)
			|| !ft_strncmp(data->map_file + i, "C ", 2))
			j++;
		if (j == 6)
		{
			while (data->map_file[i] && data->map_file[i] != '\n')
				i++;
			break ;
		}
		i++;
	}
	return (i);
}

void	is_empty_map(t_data *data)
{
	int	i;
	
	i = 0;
	while (data->map[i])
	{
		if (ft_strchr("01NSEW ", data->map[i][0]))
			return ;
		i++;
	}
	exit_game("Map can't be empty.", data, -1);
}

void	check_map(t_data *data)
{
	int		i;
	int		map_len;

	i = -1;
	map_len = array_len(data->map) - 1;
	while (map_len > 0 && data->map[map_len][0] == '\n')
		map_len--;
	while (data->map[++i] && i <= map_len)
	{
		if (i == 0 || i == map_len)
			check_border(data->map[i], data);
		if (data->map[i][0] == '\n')
			exit_game("Invalid line in map.", data, -1);
		if (check_line(data->map[i]) == -1)
			exit_game("Invalid border in map.", data, -1);
		if (check_if_map_closed(data, data->map[i], i))
			exit_game("Map is not closed.", data, -1);
		if (check_player(data) == -1)
			exit_game("Number of players is invalid.", data, -1);
		i++;
	}
}

int	check_if_map_closed(t_data *data, char *line, int i)
{
	int	j;
	int	len;
	
	j = 0;
	len = array_len(data->map);
	while (line[j])
	{
		if (line[j] == '0' || line[j] == 'N' || line[j] == 'S'
			|| line[j] == 'E' || line[j] == 'W')
		{
			if (line[j - 1] && line[j - 1] == ' ')
				return (-1);
			if (line[j + 1] && line[j + 1] == ' ')
				return (-1);
			if (data->map[i - 2] && data->map[i - 2][j] == ' ')
				return (-1);
			if (data->map[i + 2] && j > (int)ft_strlen(data->map[i + 2]))
				return (-1);
			if (data->map[i + 2] && data->map[i + 2][j] == ' ')
				return (-1);
		}
		j++;
	}
	return (0);
}

void	polish_map(t_data *data)
{
	char	**new_map;

	new_map = ft_split(data->map_file + map_start(data), '\n');
	if (!new_map)
		exit_game("Failed to split map file.", data, -1);
	free_array(data->map);
	data->map = new_map;
}