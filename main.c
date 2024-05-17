/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:21:59 by abablil           #+#    #+#             */
/*   Updated: 2024/05/17 15:20:25 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	read_map_file(int fd, t_data *data)
{
	char	*result;
	char	*temp;
	
	result = ft_strdup("");
	temp = get_next_line(fd);
	if (!temp)
	{
		free(result);
		exit_game("Map can't be empty", 1, 1);
	}
	while (temp)
	{
		data->temp = result;
		result = ft_strjoin(result, temp);
		if (!result)
		{
			free(data->temp);
			free(temp);
			exit_game("Failed to allocate result.", 1, 1);
		}
		free(data->temp);
		free(temp);
		temp = get_next_line(fd);
	}
	data->map_file = result;
	printf("%s\n", data->map_file);
}

void	look_for_map_file(char *map_path, t_data *data)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_game("Couldn't find a map with this path", 1, 1);
	read_map_file(fd, data);
}

void	validate_input(char *map_path, t_data *data)
{
	if (!ft_strlen(map_path))
		exit_game("Map name can't be empty", 1, 1);
	if (ft_strncmp(map_path + (ft_strlen(map_path) - 4), ".cub", 4))
		exit_game("Invalid map extension", 1, 1);
	look_for_map_file(map_path, data);
}

void	f(void)
{
	system("leaks cube3D");
}


int main(int total, char **args)
{
	t_data	data;
	
	// atexit(f);
	if (total != 2)
	{
		printf("\033[30m\033[102m Usage \033[0m : ./cube3D [map path]\n");
		return (1);
	}
	validate_input(args[1], &data);
	free(data.map_file);
}