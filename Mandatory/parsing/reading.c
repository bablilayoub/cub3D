/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:22:24 by abablil           #+#    #+#             */
/*   Updated: 2024/06/09 23:48:29 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*get_line(char *str, int *i)
{
	int		j;
	char	*line;

	j = 0;
	if (!str[*i])
		return (NULL);
	if (str[*i] == '\n')
	{
		(*i)++;
		line = ft_strdup("\n");
		if (!line)
			return (NULL);
		return (line);
	}
	while (str[*i + j] && str[*i + j] != '\n')
		j++;
	line = ft_substr(str, *i, j);
	if (!line)
		return (NULL);
	*i += j;
	return (line);
}

void	read_map_file(int fd, t_data *data)
{
	char	*temp;

	temp = get_next_line(fd);
	if (!temp)
		exit_game("Map file can't be empty.", data, fd, 1);
	while (temp)
	{
		if (ft_strlen(temp) > data->biggest_line)
			data->biggest_line = ft_strlen(temp);
		data->temp = data->map_file;
		data->map_file = ft_strjoin(data->map_file, temp);
		if (!data->map_file)
		{
			free(temp);
			exit_game("Failed to allocate map_file.", data, fd, 1);
		}
		free(data->temp);
		data->temp = NULL;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
}

void	get_file_data(char *map_path, t_data *data)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_game("Couldn't find a map with this path.", data, -1, 1);
	data->map_file = ft_strdup("");
	if (!data->map_file)
		exit_game("Failed to allocate map_file.", data, fd, 1);
	read_map_file(fd, data);
	if (!data->map_file)
		exit_game("Map can't be empty.", data, -1, 1);
	convert_tabs(data);
}

void	get_first_line(t_data *data, int *i, char **line)
{
	*line = get_line(data->map_file, i);
	while (*line)
	{
		if (ft_strchr("1 ", (*line)[0]))
			break ;
		free(*line);
		*line = get_line(data->map_file, i);
	}
}

void	get_map(t_data *data)
{
	int		i;
	int		k;
	char	*line;

	(1) && (i = 0, k = 0);
	data->map = malloc(sizeof(char *) * (ft_strlen(data->map_file) * 2 + 1));
	if (!data->map)
		exit_game("Failed to allocate map.", data, -1, 1);
	line = NULL;
	get_first_line(data, &i, &line);
	while (line)
	{
		data->map[k] = line;
		if (ft_strlen(line) < data->biggest_line && line[0] != '\n')
		{
			data->temp = data->map[k];
			data->map[k] = expand_line(data->map[k], data->biggest_line);
			if (!data->map[k])
				exit_game("Failed to allocate map.", data, -1, 1);
			free(data->temp);
		}
		line = get_line(data->map_file, &i);
		k++;
	}
	(1) && (data->map[k] = NULL, data->temp = NULL);
}
