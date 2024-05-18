/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:21:59 by abablil           #+#    #+#             */
/*   Updated: 2024/05/18 18:58:38 by abablil          ###   ########.fr       */
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

int	check_item(char *key)
{
	char	**valid_items;
	int		i;

	i = -1;
	valid_items = ft_split(VALID_ITEMS, ':');
	if (!valid_items)
		return (0);
	while (valid_items[++i])
	{
		if (ft_strncmp(valid_items[i], key, ft_strlen(key)) == 0)
		{
			free_array(valid_items);
			return (1);
		}
	}
	free_array(valid_items);
	return (0);
}

int	is_valid_item(char *line, t_data *data)
{
	char	**key_val;

	if (!line)
		return (0);
	key_val = ft_split(line, ' ');
	if (!key_val)
		return (0);
	if (array_len(key_val) != 2 || !check_item(key_val[0]))
	{
		free_array(key_val);
		return (0);
	}
	if (ft_strncmp(key_val[0], "NO", ft_strlen(key_val[0])) == 0)
	{ 
		if (!data->north_texture)
			data->north_texture = ft_strdup(key_val[1]);
		else
		{
			free_array(key_val);
			return (0);
		}
	}
	else if (ft_strncmp(key_val[0], "SO", ft_strlen(key_val[0])) == 0)
	{
		if (!data->south_texture)
			data->south_texture = ft_strdup(key_val[1]);
		else
		{
			free_array(key_val);
			return (0);
		}
	}
	else if (ft_strncmp(key_val[0], "WE", ft_strlen(key_val[0])) == 0)
	{
		if (!data->west_texture)
			data->west_texture = ft_strdup(key_val[1]);
		else
		{
			free_array(key_val);
			return (0);
		}
	}
	else if (ft_strncmp(key_val[0], "EA", ft_strlen(key_val[0])) == 0)
	{
		if (!data->east_texture)
			data->east_texture = ft_strdup(key_val[1]);
		else
		{
			free_array(key_val);
			return (0);
		}
	}
	else if (ft_strncmp(key_val[0], "F", ft_strlen(key_val[0])) == 0)
	{
		if (!data->floor_color)
			data->floor_color = ft_strdup(key_val[1]);
		else
		{
			free_array(key_val);
			return (0);
		}
	}
	else if (ft_strncmp(key_val[0], "C", ft_strlen(key_val[0])) == 0)
	{
		if (!data->ceiling_color)
			data->ceiling_color = ft_strdup(key_val[1]);
		else
		{
			free_array(key_val);
			return (0);
		}
	}
	free_array(key_val);
	return (1);
}

void	get_textures(t_data *data)
{
	char	**map_lines;
	int		valid_lines;
	int		i;

	i = -1;
	valid_lines = 0;
	map_lines = ft_split(data->map_file, '\n');
	if (!map_lines)
	{
		free(data->map_file);
		exit_game("Failed to allocate map_lines.", 1, 1);
	}
	while (map_lines[++i])
	{
		if (valid_lines == 6)
		{
			free_array(map_lines);
			break ;
		}
		if (ft_strlen(map_lines[i]) != 1 && map_lines[i][0] != '\n')
			valid_lines++;
		if (!is_valid_item(map_lines[i], data))
		{
			free_array(map_lines);
			free(data->map_file);
			exit_game("Invalid map items.", 1, 1);
		}
	}
}

void	check_textures(t_data *data)
{
	if (!data->north_texture)
		exit_game("North texture is missing.", 1, 1);
	if (!data->south_texture)
		exit_game("South texture is missing.", 1, 1);
	if (!data->west_texture)
		exit_game("West texture is missing.", 1, 1);
	if (!data->east_texture)
		exit_game("Eeast texture is missing.", 1, 1);
	if (!data->floor_color)
		exit_game("Floor color is missing.", 1, 1);
	if (!data->ceiling_color)
		exit_game("Ceiling color is missing.", 1, 1);
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
	check_textures(data);
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

void	free_data(t_data *data)
{
	free(data->map_file);
	free(data->north_texture);
	free(data->south_texture);
	free(data->west_texture);
	free(data->east_texture);
	free(data->floor_color);
	free(data->ceiling_color);
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
	free_data(&data);
}
