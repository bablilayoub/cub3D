/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:21:59 by abablil           #+#    #+#             */
/*   Updated: 2024/05/21 23:56:40 by abablil          ###   ########.fr       */
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

int	valid_map_item(char *line, int i)
{
	char	**valid_map_items;
	int		k;

	k = 0;
	valid_map_items = ft_split(VALID_MAP_ITEMS, ':');
	if (!valid_map_items)
		return (0);
	while (valid_map_items[k])
	{
		if (line[i] == valid_map_items[k][0]
			|| line[i] == ' ' || line[i] == '\t'
			|| line[i] == '\n')
		{
			free_array(valid_map_items);
			return (1);
		}
		k++;
	}
	free_array(valid_map_items);
	return (0);
}

int	is_valid_border_line(char *line)
{
	size_t	k;
	size_t	len;

	k = 0;
	len = ft_strlen(line);
	while (line[k] == ' ' || line[k] == '\t')
		k++;
	if (line[k] != '1' || line[len - 1] != '1')
		return (0);
	while (line[k] == ' ' || line[k] == '\t' || line[k] == '1')
		k++;
	return (k == len);
}

int	is_valid_middle_line(char *line, size_t len, char *prev_line, char  *next_line)
{
	size_t	k;

	k = 0;
	while (line[k] && (line[k] == ' ' || line[k] == '\t'))
		k++;
	if (line[k] && (line[k] != '1' || line[len - 1] != '1'))
		return (0);
	while (line[k] && line[k] != ' ' && line[k] != '\t')
		k++;
	while (line[k])
	{
		if (line[k] == ' ' || line[k] == '\t')
		{
			if (line[k + 1] && line[k + 1] != ' ' && line[k + 1] != '1')
				return (0);
			if (line[k - 1] && line[k - 1] != ' ' && line[k - 1] != '1')
				return (0);
			if (prev_line && prev_line[k] != ' ' && prev_line[k] != '1')
				return (0);
			if (next_line && next_line[k] != ' ' && next_line[k] != '1')
				return (0);
		}
		k++;
	}
	return (1);
}

int	check_from_the_start(char *line, char *to_comp)
{
	int	spaces_count;

	if (!to_comp || !to_comp[0])
		return (1);
	spaces_count = 0;
	while (line[spaces_count] && line[spaces_count] == ' ')
		spaces_count++;
	if (spaces_count == 0)
		return (1);
	spaces_count--;
	while (to_comp[spaces_count] && to_comp[spaces_count] == '1')
		spaces_count--;
	while (to_comp[spaces_count] && to_comp[spaces_count] == ' ')
		spaces_count--;
	if (spaces_count < 0)
		return (1);
	return (0);
}

int	is_line_closed(char *line, char *to_comp, int flag)
{
	size_t	len;
	size_t	to_comp_len;

	if (!to_comp)
		return (1);
	len = ft_strlen(line);
	to_comp_len = ft_strlen(to_comp);
	if (len < to_comp_len)
	{
		while (to_comp[len] && to_comp[len] == '1')
			len++;
		if (len != to_comp_len)
			return (0);
	}
	if (flag && !check_from_the_start(line, to_comp))
		return (0);
	return (1);
}

void	check_walls(char **map_lines, int i)
{
	int	arrlen;
	int	default_i;

	default_i = i;
	if (!map_lines || !map_lines[i])
		exit_game("Invalid map.", 1, 1);
	arrlen = array_len(map_lines) - 1;
	if (!is_valid_border_line(map_lines[i]))
		exit_game("Invalid first line of the map.", 1, 1);
	while (map_lines[i])
	{
		if (!is_valid_middle_line(map_lines[i], ft_strlen(map_lines[i]),
				map_lines[i - 1], map_lines[i + 1]))
			exit_game("Invalid middle line of the map.", 1, 1);
		if (!is_line_closed(map_lines[i], map_lines[i - 1], (default_i != i)))
			exit_game("Map not closed.", 1, 1);
		if (!is_line_closed(map_lines[i], map_lines[i + 1], 0))
			exit_game("Map not closed.", 1, 1);
		i++;
	}
	if (!is_valid_border_line(map_lines[arrlen]))
		exit_game("Invalid last line of the map.", 1, 1);
}

void	check_player(char **map_lines, int i)
{
	int	count_players;
	int	k;

	count_players = 0;
	while (map_lines[i])
	{
		k = -1;
		while (map_lines[i][++k])
		{
			if (map_lines[i][k] == 'N'
				|| map_lines[i][k] == 'S'
				|| map_lines[i][k] == 'E'
				|| map_lines[i][k] == 'W')
			count_players++;
		}
		i++;
	}
	if (count_players != 1)
	{
		free_array(map_lines);
		exit_game("Map must have 1 player", 1, 1);
	}
}

void	validate_map(char **map_lines, int i)
{
	char	**valid_map_items;
	size_t	k;
	int		default_i;

	k = 0;
	default_i = i;
	valid_map_items = ft_split(VALID_MAP_ITEMS, ':');
	if (!valid_map_items)
		exit_game("Failed to allocate valid_map_items.", 1, 1);
	while (map_lines[i])
	{
		k = 0;
		while (valid_map_item(map_lines[i], k))
			k++;
		if (k != ft_strlen(map_lines[i]))
		{
			free_array(valid_map_items);
			exit_game("Invalid map items.", 1, 1);
		}
		i++;
	}
	check_walls(map_lines, default_i);
	check_player(map_lines, default_i);
	free_array(valid_map_items);
	free_array(map_lines);
}

void	get_textures(t_data *data)
{
	char	**map_lines;
	int		valid_lines;
	int		i;

	(1) && (i = -1, valid_lines = 0);
	map_lines = ft_split(data->map_file, '\n');
	if (!map_lines)
	{
		free(data->map_file);
		exit_game("Failed to allocate map_lines.", 1, 1);
	}
	while (map_lines[++i])
	{
		if (valid_lines == 6)
			break ;
		if (ft_strlen(map_lines[i]) != 1 && map_lines[i][0] != '\n')
			valid_lines++;
		if (!is_valid_item(map_lines[i], data))
		{
			free_array(map_lines);
			free(data->map_file);
			exit_game("Invalid map items.", 1, 1);
		}
	}
	validate_map(map_lines, i);
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

int	convert_tabs_to_spaces(t_data *data)
{
	char	*new_map;
	int		i;
	int 	length; 
	int		k;
	
	(1) && (i = -1, k = 0);
	length  = ft_strlen(data->map_file) * 4 + 1;
	new_map = (char *)malloc(sizeof(char) * length);
	if (!new_map)
		return (0);
	i = -1;
	while (data->map_file[++i])
	{
		if (data->map_file[i] == '\t')
		{
			(1) && (new_map[k++] = ' ', new_map[k++] = ' ',
				new_map[k++] = ' ', new_map[k++] = ' ');
		}
		else
			new_map[k++] = data->map_file[i];
	}
	new_map[k] = '\0';
	free(data->map_file);
	data->map_file = new_map;
	return (1);
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
	if (!data->map_file)
		return ;
	if (!convert_tabs_to_spaces(data))
	{
		free(data->map_file);
		exit_game("Failed to allocate new_map.", 1, 1);
	}
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
	// printf("%s\n", data->map_file);
}

void	f(void)
{
	system("leaks cube3D");
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
