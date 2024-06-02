/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:25:36 by abablil           #+#    #+#             */
/*   Updated: 2024/06/01 21:58:31 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_first_six_lines(t_data *data)
{
	char	**lines;
	int		i;
	
	i = 0;
	lines = ft_split(data->map_file, '\n');
	if (!lines)
		exit_game("Failed to split map file.", data, -1, 1);
	while (lines[i] && i < 6)
	{
		if (ft_strncmp(lines[i], "NO ", 3)
			&& ft_strncmp(lines[i], "SO ", 3)
			&& ft_strncmp(lines[i], "WE ", 3)
			&& ft_strncmp(lines[i], "EA ", 3)
			&& ft_strncmp(lines[i], "F ", 2)
			&& ft_strncmp(lines[i], "C ", 2))
		{
			free_array(lines);
			exit_game("Invalid map configuration.", data, -1, 1);
		}
		i++;
	}
	free_array(lines);
}

void	check_border(char *line, t_data *data)
{
	int	i;
	
	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			exit_game("Invalid border in map.", data, -1, 1);
		i++;
	}
}

int	check_line(char *line)
{
	int	i;
	int	k;

	(1) && (i = 0, k = ft_strlen(line) - 1);
	while (line[i] == ' ')
		i++;
	while (line[k] == ' ')
		k--;
	if (line[i] != '1' || line[k] != '1')
		return (-1);
	return (0);
}

int	check_player(t_data *data)
{
	int	i;
	int	j;
	int	player;

	(1) && (i = 0, j = 0, player = 0);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_strchr("NSEW", data->map[i][j]))
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (-1);
	return (0);
}

void	check_duplicated_keys(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (data->map_file[i])
	{
		if (data->map_file[i] == 'N' && data->map_file[i + 1] == 'O' && data->map_file[i + 2] == ' ')
			count++;
		else if (data->map_file[i] == 'S' && data->map_file[i + 1] == 'O' && data->map_file[i + 2] == ' ')
			count++;
		else if (data->map_file[i] == 'W' && data->map_file[i + 1] == 'E' && data->map_file[i + 2] == ' ')
			count++;
		else if (data->map_file[i] == 'E' && data->map_file[i + 1] == 'A' && data->map_file[i + 2] == ' ')
			count++;
		else if (data->map_file[i] == 'F' && data->map_file[i + 1] == ' ')
			count++;
		else if (data->map_file[i] == 'C' && data->map_file[i + 1] == ' ')
			count++;
		if (count > 6)
		{
			printf("count = %d\n", count);
			exit_game("Duplicated texture or color.", data, -1, 1);
		}
		i++;
	}
}
