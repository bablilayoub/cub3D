/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:21:59 by abablil           #+#    #+#             */
/*   Updated: 2024/05/18 09:15:22 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	read_map_file(int fd, t_data *data)
{
	char	*temp;

	temp = get_next_line(fd);
	if (!temp)
	{
		free(data->map_file);
		close(fd);
		exit_game("Map can't be empty.", 1, 1);
	}
	while (temp)
	{
		data->temp = data->map_file;
		data->map_file = ft_strjoin(data->map_file, temp);
		if (!data->map_file)
		{
			free(data->temp);
			free(temp);
			close(fd);
			exit_game("Failed to allocate result.", 1, 1);
		}
		free(data->temp);
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
}

int	is_valid_item(char *line)
{
	int	i;

	(void)line;
	i = -1;
	
	return (1);
}

void	get_textures(t_data *data)
{
	char	**map_lines;
	int		i;

	i = -1;
	map_lines = ft_split(data->map_file, '\n');
	if (!map_lines)
	{
		free(data->map_file);
		exit_game("Failed to allocate map_lines.", 1, 1);
	}
	while (map_lines[++i])
	{
		if (!is_valid_item(map_lines[i]))
		{
			free_array(map_lines);
			free(data->map_file);
			exit_game("Invalid map items.", 1, 1);
		}
	}
}

void	look_for_map_file(char *map_path, t_data *data)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_game("Couldn't find a map with this path.", 1, 1);
	data->map_file = ft_strdup("");
	if (!data->map_file)
		exit_game("Failed to allocate map_file.", 1, 1);
	read_map_file(fd, data);
	// printf("%s", data->map_file);
	get_textures(data);
}

void	validate_input(char *map_path, t_data *data)
{
	if (!ft_strlen(map_path))
		exit_game("Map name can't be empty.", 1, 1);
	if (ft_strncmp(map_path + (ft_strlen(map_path) - 4), ".cub", 4))
		exit_game("Invalid map extension.", 1, 1);
	look_for_map_file(map_path, data);
}

void	f(void)
{
	system("leaks cube3D");
}

void	r(void)
{
	system("lsof -c cube3D");
}

int	main(int total, char **args)
{
	t_data	data;

	// atexit(f);
	if (total != 2)
	{
		printf("\033[30m\033[102m Usage \033[0m : ./cube3D [map path]\n");
		return (1);
	}
	ft_memset(&data, 0, sizeof(t_data));
	validate_input(args[1], &data);
	free(data.map_file);
}
