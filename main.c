/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:21:59 by abablil           #+#    #+#             */
/*   Updated: 2024/05/24 23:43:06 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	f(void)
{
	system("leaks cub3D");
}

void	draw_map(t_data *data, void *mlx, void *win)
{
	int		pixel_size;
	int		x;
	int		y;
	int		color;
	int		j;
	int		i;

	pixel_size = 30;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				color = 0x00FF00;
			else if (data->map[y][x] == '0')
				color = 0xFFFFFF;
			else if (data->map[y][x] == 'N' || data->map[y][x] == 'S' || data->map[y][x] == 'W' || data->map[y][x] == 'E')
				color = 0x0000FF;
			else
				color = 0x000000;
			j = 0;
			while (j < pixel_size)
			{
				i = 0;
				while (i < pixel_size)
				{
					mlx_pixel_put(mlx, win, x * pixel_size + i, y * pixel_size + j, color);
					i++;
				}
				j++;
			}
			x++;
		}
		y++;
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		free_data(data);
		exit(0);
	}
	return (0);
}

int	close_game(t_data *data)
{
	free_data(data);
	exit(0);
}

int	biggest_line(char **map)
{
	size_t	i;
	size_t	biggest;

	i = 0;
	biggest = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > biggest)
			biggest = ft_strlen(map[i]);
		i++;
	}
	return (biggest);
}

void	init_game(t_data *data)
{
	void	*img;
	int		window_width;
	int		window_height;
	
	window_width = biggest_line(data->map) * 30;
	window_height = array_len(data->map) * 30;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, window_width, window_height, "cub3D");
	img = mlx_new_image(data->mlx, window_width, window_height);
	mlx_put_image_to_window(data->mlx, data->win, img, 0, 0);
	draw_map(data, data->mlx, data->win);
	mlx_hook(data->win, 17, 0, close_game, data);
	mlx_hook(data->win, 2, 0, key_hook, data);
	mlx_loop(data->mlx);
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
	init_game(&data);
	free_data(&data);
}
