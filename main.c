/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:21:59 by abablil           #+#    #+#             */
/*   Updated: 2024/05/23 15:47:47 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}

void	print_textures(t_data *data)
{
	printf("North texture: |%s|\n", data->north_texture);
	printf("South texture: |%s|\n", data->south_texture);
	printf("West texture: |%s|\n", data->west_texture);
	printf("East texture: |%s|\n", data->east_texture);
	printf("\n");
}

void	print_colors(t_data *data)
{
	printf("Floor color: |%s|\n", data->floor_color);
	printf("Ceiling color: |%s|\n", data->ceiling_color);
	printf("\n");
}

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
		exit_game("Map can't be empty.", data, fd);
	while (temp)
	{
		if (ft_strlen(temp) > data->biggest_line)
			data->biggest_line = ft_strlen(temp);
		data->temp = data->map_file;
		data->map_file = ft_strjoin(data->map_file, temp);
		if (!data->map_file)
		{
			free(temp);
			exit_game("Failed to allocate map_file.", data, fd);
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
		exit_game("Couldn't find a map with this path.", data, -1);
	data->map_file = ft_strdup("");
	if (!data->map_file)
		exit_game("Failed to allocate map_file.", data, -1);
	read_map_file(fd, data);
	if (!data->map_file)
		exit_game("Map can't be empty.", data, -1);
}

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
		exit_game("Failed to allocate map.", data, -1);
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
				exit_game("Failed to allocate map.", data, -1);
			free(data->temp);
		}
		line = get_line(data->map_file, &i);
		k++;
	}
	(1) && (data->map[k] = NULL, data->temp = NULL);
}

char	*get_texture(t_data *data, int *i, char *texture_data)
{
	char	*texture;
	int		j;

	if (texture_data)
		exit_game("Duplicate texture.", data, -1);
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
	int	i;

	i = 0;
	while (data->map_file[i])
	{
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
}

void	check_textures_path(t_data *data)
{
	int	fd;

	fd = open(data->north_texture, O_RDONLY);
	if (fd == -1)
		exit_game("Invalid north texture path.", data, -1);
	close(fd);
	fd = open(data->south_texture, O_RDONLY);
	if (fd == -1)
		exit_game("Invalid south texture path.", data, -1);
	close(fd);
	fd = open(data->west_texture, O_RDONLY);
	if (fd == -1)
		exit_game("Invalid west texture path.", data, -1);
	close(fd);
	fd = open(data->east_texture, O_RDONLY);
	if (fd == -1)
		exit_game("Invalid east texture path.", data, -1);
	close(fd);
}

void	check_rgb(char *color, t_data *data)
{
	char	**rgb;
	
	rgb = ft_split(color, ',');
	if (!rgb)
		exit_game("Failed to split color.", data, -1);
	if (array_len(rgb) != 3)
	{
		free_array(rgb);
		exit_game("Invalid color format.", data, -1);
	}
	if (!is_number(rgb[0]) || !is_number(rgb[1]) || !is_number(rgb[2]))
	{
		free_array(rgb);
		exit_game("Invalid color format.", data, -1);
	}
	if (ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255
		|| ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255
		|| ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255)
	{
		free_array(rgb);
		exit_game("Invalid color format.", data, -1);
	}
	free_array(rgb);
}

void	check_colors_format(t_data *data)
{
	if (!ft_strchr(data->floor_color, ','))
		exit_game("Invalid floor color format.", data, -1);
	if (!ft_strchr(data->ceiling_color, ','))
		exit_game("Invalid ceiling color format.", data, -1);
	check_rgb(data->floor_color, data);
	check_rgb(data->ceiling_color, data);
}

void	check_textures(t_data *data)
{
	if (!data->north_texture || !data->south_texture
		|| !data->west_texture || !data->east_texture)
		exit_game("Missing textures.", data, -1);
	if (!data->floor_color || !data->ceiling_color)
		exit_game("Missing colors.", data, -1);
	check_textures_path(data);
	check_colors_format(data);
}

void	parsing(char *map_path, t_data *data)
{
	if (!map_path || !ft_strlen(map_path))
		exit_game("Map name can't be empty.", data, -1);
	if (ft_strncmp(map_path + (ft_strlen(map_path) - 4), ".cub", 4))
		exit_game("Invalid map extension.", data, -1);
	get_file_data(map_path, data);
	get_textures(data);
	check_textures(data);
	get_map(data);
	print_textures(data);
	print_colors(data);
	print_map(data->map);
}

void	f(void)
{
	system("leaks cub3D");
}

int	main(int total, char **args)
{
	t_data	data;

	// atexit(f);
	if (total != 2)
	{
		printf("\033[30m\033[102m Usage \033[0m : ./cub3D [map path]\n");
		return (1);
	}
	ft_memset(&data, 0, sizeof(t_data));
	parsing(args[1], &data);
	free_data(&data);
}
